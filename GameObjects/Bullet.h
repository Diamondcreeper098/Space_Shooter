//The class responsible for bullets

#pragma once
#include <SFML/Graphics.hpp>
#include "../TextureManager.h"

class Bullet {
private:
    sf::Sprite m_sprite;
    bool isInit = false;
public:
    Bullet() = default;
    void Instantiate(sf::Vector2i position);
    void Update();
    sf::Sprite& GetSprite();
    void Destroy();
};
