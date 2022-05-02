#include "Application/Application.h"
#include "TextureManager.h"

//Defining the Textures dictionary
std::map<std::string, sf::Texture> TextureManager::Textures;

int main() {


    //Running the App
    Application* x = new Application();
    x->Run();
    delete x;
    return 0;
}
