#pragma once
#include <iostream>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>
#include "Renderer.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

class Game {
public:
    Game();
    
    ~Game() = default;

    void run();


private:

    std::shared_ptr<sf::Window> _window;

    sf::ContextSettings _settings;
    std::vector<Cube> _renderObjects;

    std::unique_ptr<Renderer> _renderer;
};
