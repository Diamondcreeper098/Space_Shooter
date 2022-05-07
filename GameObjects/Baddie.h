//The class responsible for Opponents

#pragma once
#include <SFML/Graphics.hpp>

class Baddie {
private:
    sf::Sprite m_sprite;
public:
    bool isDestroyed = false;
    Baddie()= default;
    void Instantiate(sf::Vector2i position);
    void Update();
    sf::Sprite GetSprite();
    void Destroy();
};
