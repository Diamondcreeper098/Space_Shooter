#include "Bullet.h"
#include <vector>

class BulletHandler {
public:
    static std::vector<Bullet> Bullets;

    static void Shoot(sf::Vector2i position){
        Bullets.emplace_back();
        Bullets.back().Instantiate(position);
    }

    static void DrawAll(sf::RenderWindow& renderer){
        for (int i = 0; i < Bullets.size(); ++i) {
            renderer.draw(Bullets[i].GetSprite());
        }
    }

    static void UpdateAll(){
        for (int i = 0; i < Bullets.size(); ++i) {
            Bullets[i].Update();
        }
    }
};

