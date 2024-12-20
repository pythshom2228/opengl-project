#pragma once
#include <iostream>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>


class Game {
public:
    Game();
    
    ~Game();

    void run();


private:
    std::shared_ptr<sf::Window> _window;
    sf::ContextSettings _settings;

    struct _Impl;
    std::unique_ptr<_Impl> _pImpl;

};
