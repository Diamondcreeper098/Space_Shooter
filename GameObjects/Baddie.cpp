#include "Baddie.h"
#include "../TextureManager.h"
#include "../GameStates.h"
#include "../GameObjects/BulletHandler.h"

void Baddie::Instantiate(sf::Vector2i position) {

    //Loading the texture from memory to the sprite
    m_sprite.setTexture(TextureManager::Textures["Invader"]);

    //Setting the sprite's Position
    m_sprite.setPosition(position.x, position.y);
}

sf::Sprite Baddie::GetSprite() {
    return m_sprite;
}

void Baddie::Update() {
    for (int i = 0; i < BulletHandler::Bullets.size(); ++i) {
        if (BulletHandler::Bullets[i].GetSprite().getGlobalBounds().intersects(GetSprite().getGlobalBounds())){
            BulletHandler::Bullets.erase(BulletHandler::Bullets.begin() + i);
            Destroy();
        }
    }
}

void Baddie::Destroy() {

    //Disabling the invader
    isDestroyed = true;

    //Hiding it
    m_sprite.setPosition(0,0);
    m_sprite.setScale(0,0);
}
