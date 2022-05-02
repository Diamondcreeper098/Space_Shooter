#include "Player.h"
#include "../GameStates.h"
#include <iostream>

Player::Player() {}

void Player::Instantiate() {
    // Loading the texture from the memory to Sprite
    m_sprite.setTexture(TextureManager::Textures["Ship"]);
    m_sprite.setPosition(0, GameStates::windowHeight - 40);
}

void Player::Update() {
        m_sprite.move(m_accel, 0);
}

void Player::Destroy() {

}

sf::Sprite& Player::GetSprite() {
    return m_sprite;
}
