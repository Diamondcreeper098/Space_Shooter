//The Main Application

#pragma once
#include "../TextureManager.h"
#include "../GameStates.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/Baddie.h"
#include <SFML/Graphics.hpp>
#include <vector>

// Main menu
struct MainMenu{
    static int SelectionIndex;
    static std::string Title;
    static std::string Message;
    static std::vector<std::string> Items;
    static bool isOpen;
    static void OpenMenu(const std::string& message){
        Items.clear();
        SelectionIndex = 0;
        Title = "Space Shooter";
        Message = message;
        Items.emplace_back("Start");
        Items.emplace_back("End");
        isOpen = true;
    }
    static void CloseMenu(){
        isOpen = false;
    }
};

class Application {
private:
    sf::RenderWindow m_window;
    Player player;
    std::vector<Baddie> baddies;
    sf::Clock clock;
    sf::Font font;
    bool hadBegun = false;
public:
    Application() = default;
    void Run();
    void GameLoop();
    void InitGameObjects();
};


