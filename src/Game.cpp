#include "include/Game.h"



Game::Game() {
    _settings.depthBits = 24;
    _settings.stencilBits = 8;
    _settings.antialiasingLevel = 4;
    _settings.majorVersion = 4;
    _settings.minorVersion = 3;
    _settings.attributeFlags = sf::ContextSettings::Core;

    _window = std::make_unique<sf::Window>(sf::Window(
        sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT),
        "Game",
        sf::ContextSettings::Default,
        this->_settings
    ));

}

void Game::run() {
    bool isRunning = true;


    
    while(isRunning) {
        sf::Event event;
         while (_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                isRunning = false;
            }
            else if (event.type == sf::Event::Resized)
            {
                // adjust the viewport when the window is resized
                glViewport(0, 0, event.size.width, event.size.height);
            }
        }
        _window->setActive(true);

        _renderer.render();

        _window->setActive(false);
        
        _window->display();
    }
    _window->close();
}

