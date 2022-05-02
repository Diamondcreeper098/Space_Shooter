#pragma once
#include "../TextureManager.h"
#include "../GameStates.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/Baddie.h"
#include "../GameObjects/Bullet.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Application {
private:
    sf::RenderWindow m_window;
    Player player;
    Bullet bullet;
    std::vector<Baddie> baddies;
    sf::Clock clock;
public:
    Application();
    void Run();
    void GameLoop();
};


