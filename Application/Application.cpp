#include "Application.h"
#include <iostream>

Application::Application() {}

void Application::Run() {

    //Creating the window
    m_window.create(sf::VideoMode(GameStates::windowWidth,GameStates::windowHeight)
                    ,"Space invader");
    m_window.setFramerateLimit(60);

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
    GameLoop();
}

void Application::GameLoop() {
    while(m_window.isOpen()){
        sf::Time dt = clock.restart();

        //Events
        sf::Event event;
        while (m_window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                m_window.close();
            player.Update(event, dt, bullet);
        }

        //Updating
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
