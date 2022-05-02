#include "Baddie.h"
#include "../TextureManager.h"
#include "../GameStates.h"

void Baddie::Instantiate(sf::Vector2i position) {

    //Loading the texture from memory to the sprite
    m_sprite.setTexture(TextureManager::Textures["Invader"]);

    //Setting the sprite's Position
    m_sprite.setPosition(position.x, position.y);
}

sf::Sprite Baddie::GetSprite() {
    return m_sprite;
}

void Baddie::Update(Bullet &bullet) {
    if(!isDestroyed) {
        //Checking for collision with a bullet
        if (bullet.GetSprite().getGlobalBounds().intersects(m_sprite.getGlobalBounds())) {

            //Destroying the bullet and the invader
            bullet.Destroy();
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
