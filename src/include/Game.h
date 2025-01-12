#pragma once
#include <iostream>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>
#include "Cube.h"
#include "Player.h"
#include "Renderer.h"


class Game {
public:
    Game();
    
    ~Game();

    void run();


private:
    std::shared_ptr<sf::Window> _window;
    sf::ContextSettings _settings;

    std::vector<Cube> _renderObjects;
    std::unique_ptr<Player> _player;
    std::unique_ptr<Renderer>   _renderer;

};
