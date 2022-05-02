#include "Bullet.h"
#include "../GameStates.h"

void Bullet::Update() {

    //Moving the bullet upwards 'til it collides with an invader or moves out of the screen
    if(isInit)
        m_sprite.move(0, -40);
    if(m_sprite.getPosition().y <= 0)
        Destroy();
}

void Bullet::Instantiate(sf::Vector2i position) {

    //Loading the Bullet's texture from memory to the sprite
    m_sprite.setTexture(TextureManager::Textures["Bullet"]);
    m_sprite.setPosition(position.x, position.y);
    m_sprite.setScale(1,1);

    //Enabling the Bullet
    isInit = true;
}

sf::Sprite Bullet::GetSprite() {
    return m_sprite;
}

void Bullet::Destroy() {

    //Hiding and Disabling the Bullet
    m_sprite.setPosition(0,0);
    m_sprite.setScale(0,0);
    isInit = false;
}
