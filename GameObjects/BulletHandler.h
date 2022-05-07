//The class responsible for Handling Bullets

#include "Bullet.h"
#include <vector>

class BulletHandler {
public:
    static std::vector<Bullet> Bullets; //The array that holds the bullets

    //Instantiates the Bullet GameObjects and then Shoots them.
    static void Shoot(sf::Vector2i position){
        Bullets.emplace_back();
        Bullets.back().Instantiate(position);
    }

    //Renders the Bullets
    static void DrawAll(sf::RenderWindow& renderer){
        for (auto & Bullet : Bullets) {
            renderer.draw(Bullet.GetSprite());
        }
    }

    //Tells the bullets to move (Updates them).
    static void UpdateAll(){
        for (auto & Bullet : Bullets) {
            Bullet.Update();
        }
    }
};

