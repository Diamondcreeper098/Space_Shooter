#pragma once
#include <SFML/Graphics.hpp>
#include "../GameObjects/Bullet.h"

class Baddie {
private:
    sf::Sprite m_sprite;
public:
    bool isDestroyed = false;
    Baddie()= default;
    void Instantiate(sf::Vector2i position);
    void Update(Bullet &bullet);
    sf::Sprite GetSprite();
    void Destroy();
};
