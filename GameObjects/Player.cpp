#include "Player.h"
#include "../GameStates.h"
#include <iostream>

Player::Player() {}

void Player::Instantiate() {
    // Loading the texture from the memory to Sprite
    m_sprite.setTexture(TextureManager::Textures["Ship"]);
    m_sprite.setPosition(0, GameStates::windowHeight - 40);
}

void Player::Update(sf::Event& evt,sf::Time dt, Bullet &bullet) {

    //Keyboard Input
    if(evt.type == sf::Event::KeyPressed){

        //Moving the Ship to left if A is pressed
        if(evt.key.code == sf::Keyboard::A){
            float acc = -500;
            if((m_sprite.getPosition().x - 10) <= 0) acc = 0;
            m_sprite.move(dt.asSeconds()*acc, 0);
        }

        //Moving the Ship to Right if D is pressed
        else if(evt.key.code == sf::Keyboard::D){
            float acc = 500;
            if((m_sprite.getPosition().x + 70) >= GameStates::windowWidth) acc = 0;
            m_sprite.move(dt.asSeconds()*acc, 0);
        }

        //Shooting the bullet if Space is pressed
        else if(evt.key.code == sf::Keyboard::Space){
            bullet.Instantiate(sf::Vector2i (((m_sprite.getPosition().x + 28)), m_sprite.getPosition().y));
        }
    }
}

void Player::Destroy() {

}

sf::Sprite& Player::GetSprite() {
    return m_sprite;
}
