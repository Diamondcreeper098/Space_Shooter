#include "Application.h"
#include "../GameObjects/BulletHandler.h"
#include <iostream>

Application::Application() {}

void Application::Run() {

    //Creating the window
    m_window.create(sf::VideoMode(GameStates::windowWidth,GameStates::windowHeight)
                    ,"Space invader");
    m_window.setFramerateLimit(60);

    //Loading Textures to the memory
    TextureManager::register_texture("Ship", "./assets/images/Ship.png"
            , sf::IntRect(0,0,60,32));
    TextureManager::register_texture("Invader", "./assets/images/InvaderA1.png"
            , sf::IntRect(0,0,48,32));
    TextureManager::register_texture("Bullet", "./assets/images/Bullet.png"
            , sf::IntRect(0,0,6,17));

    //Initializing GameObjects
    player.Instantiate();
    int x = 50, y = 10;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 15; ++j) {
            baddies.emplace_back();
            baddies.back().Instantiate(sf::Vector2i(x, y));
            x += 68;
        }
        x = 50;
        y +=52;
    }
    sf::Time dt = clock.restart();
    GameLoop();
}

void Application::GameLoop() {
    while(m_window.isOpen()){
        sf::Time dt = clock.restart();

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
            }

            //Key Released
            else if(event.type == sf::Event::KeyReleased){

                //Stopping the ship's movement
                if (event.key.code == sf::Keyboard::A) {
                    player.SetAcceleration(0);
                } else if (event.key.code == sf::Keyboard::D){
                    player.SetAcceleration(0);
                }
            }
        }

        //Updating
        player.Update();
        bullet.Update();
        for (int i = 0; i < baddies.size(); ++i) {
            baddies[i].Update(bullet);
        }
        //Drawing
        m_window.clear();
        m_window.draw(player.GetSprite());
        for (int i = 0; i < baddies.size(); ++i) {
            m_window.draw(baddies[i].GetSprite());
        }
        m_window.draw(bullet.GetSprite());
        m_window.display();

    }
}
