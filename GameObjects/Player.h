#pragma once
#include <SFML/Graphics.hpp>
#include "../TextureManager.h"
#include "../GameObjects/Bullet.h"


class Player {
private:
    sf::Sprite m_sprite;
    int m_accel = 0;
public:
    Player();
    void Instantiate();
    void Update(sf::Event &evt,sf::Time dt, Bullet &bullet);
    sf::Sprite& GetSprite();
    void Destroy();
};


