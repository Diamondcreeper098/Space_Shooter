#include "Bullet.h"
#include <vector>

class BulletHandler {
public:
    static std::vector<Bullet> Bullets;
    static void Shoot(sf::Vector2i position){
        Bullets.emplace_back();
        Bullets.back().Instantiate(position);
    }
};

