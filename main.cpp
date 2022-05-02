#include "Application/Application.h"
#include "TextureManager.h"

//Defining the Textures dictionary
std::map<std::string, sf::Texture> TextureManager::Textures;

int main() {


    //Running the App
    Application app;
    app.Run();
    return 0;
}
