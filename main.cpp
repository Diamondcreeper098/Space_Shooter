#include "Application/Application.h"
#include "TextureManager.h"

//Defining the Textures dictionary
std::map<std::string, sf::Texture> TextureManager::Textures;

int main() {

    //Loading Textures to the memory
    TextureManager::register_texture("Ship", "./assets/images/Ship.png"
                                     , sf::IntRect(0,0,60,32));
    TextureManager::register_texture("Invader", "./assets/images/InvaderA1.png"
                                     , sf::IntRect(0,0,48,32));
    TextureManager::register_texture("Bullet", "./assets/images/Bullet.png"
            , sf::IntRect(0,0,6,17));

    //Running the App
    Application* x = new Application();
    x->Run();
    delete x;
    return 0;
}
