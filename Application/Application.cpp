#include "Application.h"
#include "../GameObjects/BulletHandler.h"
#include <iostream>

//Defining Static Variables
std::map<std::string, sf::Texture> TextureManager::Textures;
std::vector<Bullet> BulletHandler::Bullets;
int MainMenu::SelectionIndex;
std::string MainMenu::Title;
std::string MainMenu::Message;
std::vector<std::string> MainMenu::Items;
bool MainMenu::isOpen;

int bulletcooldown = 10;

void Application::Run() {

    //Creating the window
    m_window.create(sf::VideoMode(GameStates::windowWidth,GameStates::windowHeight)
                    ,"Space Shooter");
    m_window.setFramerateLimit(60);

    //Loading Textures to the memory
    TextureManager::register_texture("Ship", "./assets/images/Ship.png"
            , sf::IntRect(0,0,60,32));
    TextureManager::register_texture("Invader", "./assets/images/InvaderA1.png"
            , sf::IntRect(0,0,48,32));
    TextureManager::register_texture("Bullet", "./assets/images/Bullet.png"
            , sf::IntRect(0,0,6,17));

    if (!font.loadFromFile("./assets/unifont.ttf")) {
        std::cerr << "Font failed";
        return;
    }

    sf::Time dt = clock.restart();
    GameLoop();
}

void Application::GameLoop() {

    while(m_window.isOpen()){
        //Getting the time that every frame takes
        sf::Time dt = clock.restart();

        //If All the Opponents are dead/not spawned yet, Open the Menu
        if(baddies.empty()) {
            if (hadBegun)
                MainMenu::OpenMenu("You won!");
            else
                MainMenu::OpenMenu("");
        }
        hadBegun = true;

        //The Menu loop
        while(MainMenu::isOpen){
            sf::Event event;

            //Menu's Event loop
            while (m_window.pollEvent(event)) {
                //If we are closing the Program
                if(event.type == sf::Event::Closed) {
                    m_window.close();
                    MainMenu::CloseMenu();
                }

                //When Down Arrow key is pressed, Advance to the next item in the menu
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    ++MainMenu::SelectionIndex;
                    if (MainMenu::SelectionIndex > 1)
                        MainMenu::SelectionIndex = 0;
                //When Up Arrow key is pressed, Come back to the Previous item in the menu
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    --MainMenu::SelectionIndex;
                    if (MainMenu::SelectionIndex < 0)
                        MainMenu::SelectionIndex = 1;
                //When Enter Key is pressed, Do the related action
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                    if (MainMenu::SelectionIndex == 0)
                        InitGameObjects();
                    else
                        m_window.close();
                    MainMenu::CloseMenu();
                }
            }

            //Drawing the menu
            m_window.clear();
            sf::Text msg(MainMenu::Message, font, 30);
            msg.setPosition(20, 10);
            sf::Text title(MainMenu::Title, font, 50);
            title.setPosition(20, 50);
            m_window.draw(title);
            m_window.draw(msg);
            //The Origin Position for Menu Items
            int MenuX = 30;
            int MenuY = 110;
            //Drawing menu items
            for (int i = 0; i < MainMenu::Items.size(); ++i) {
                sf::Text text(MainMenu::Items[i], font);
                text.setPosition(MenuX, MenuY);
                if( i == MainMenu::SelectionIndex)
                    text.setFillColor(sf::Color::Green);
                m_window.draw(text);
                MenuY+=40;
            }
            m_window.display();
        }

        //Events
        sf::Event event;
        while (m_window.pollEvent(event)){

            //Window Close
            if(event.type == sf::Event::Closed)
                m_window.close();

            //Key Pressed
            else if(event.type == sf::Event::KeyPressed){

                //Steering ship to left
                if (event.key.code == sf::Keyboard::A){
                    player.SetAcceleration(-(float)GameStates::Ship_Accel * dt.asSeconds());
                }

                //Steering ship to right
                else if (event.key.code == sf::Keyboard::D){
                    player.SetAcceleration((float)GameStates::Ship_Accel * dt.asSeconds());
                }

                //Shoot a Bullet
                else if (event.key.code == sf::Keyboard::Space){
                    --bulletcooldown;
                    if (bulletcooldown <= 0) {

                        BulletHandler::Shoot(sf::Vector2i(player.GetSprite().getPosition().x + 28,
                                                          player.GetSprite().getPosition().y));
                        bulletcooldown = 10;
                    }
                }
            }

            //Key Released
            else if(event.type == sf::Event::KeyReleased){

                //Stopping the ship's movement
                if (event.key.code == sf::Keyboard::A) {
                    player.SetAcceleration(0);
                } else if (event.key.code == sf::Keyboard::D){
                    player.SetAcceleration(0);
                }
                //Resetting the Bullet Cooldown
                else if (event.key.code == sf::Keyboard::Space){
                    bulletcooldown = 0;
                }
            }
        }

        //Updating
        player.Update();
        BulletHandler::UpdateAll();
        for (int i = 0; i < baddies.size(); ++i) {
            baddies[i].Update();
            //If An Opponent is Destroyed, Remove the related item from the Opponent's Array
            if (baddies[i].isDestroyed){
                baddies.erase(baddies.begin() + i);
            }
        }
        //Drawing
        m_window.clear();
        m_window.draw(player.GetSprite());
        for (int i = 0; i < baddies.size(); ++i) {
            m_window.draw(baddies[i].GetSprite());
        }
        BulletHandler::DrawAll(m_window);
        m_window.display();

    }
}

//Initializing GameObjects
void Application::InitGameObjects() {

    player.Instantiate();
    int x = 50, y = 60;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 18; ++j) {
            baddies.emplace_back();
            baddies.back().Instantiate(sf::Vector2i(x, y));
            x += 68;
        }
        x = 50;
        y +=52;
    }
}
