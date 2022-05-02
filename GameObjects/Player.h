#pragma once
#include <SFML/Graphics.hpp>
#include "../TextureManager.h"


class Player {
private:
    sf::Sprite m_sprite;
    float m_accel = 0;
public:
    Player();
    void Instantiate();
    void Update();
    void SetAcceleration(float x) {
        m_accel = x;
    }
    sf::Sprite& GetSprite();
    void Destroy();
};


