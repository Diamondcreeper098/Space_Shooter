#pragma once
#include <map>
#include <string>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>

//A Static Class for loading the Textures into memory
class TextureManager{
public:

    // Holds the Textures
    static std::map<std::string, sf::Texture> Textures;

    // Registers (loads) The Textures into memory and appends them to the Textures Dictionary
    static void register_texture(const std::string& texture_name, const std::string& texture_path, sf::IntRect area){

        sf::Texture tmp;

        //Loads the Texture from file and throws an exception if it fails.
        if (!tmp.loadFromFile(texture_path, area)) {
            std::ostringstream oss;
            oss << "FATAL: Couldn't load Texture " << texture_name << " from " << texture_path;
            throw std::runtime_error(oss.str());
        }
        Textures.insert({texture_name,tmp});
    }
};
