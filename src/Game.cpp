#include "include/Game.h"


Game::Game() {
    _settings.depthBits = 24;
    _settings.stencilBits = 8;
    _settings.antialiasingLevel = 4;
    _settings.majorVersion = 4;
    _settings.minorVersion = 3;
    _settings.attributeFlags = sf::ContextSettings::Core;

    _window = std::make_shared<sf::Window>(
        sf::VideoMode().getDesktopMode(),
        "Minecraft",
        sf::Style::Default,
        this->_settings
    );
    _window->setFramerateLimit(120);
    _window->setMouseCursorGrabbed(true);
    _window->setMouseCursorVisible(false);

    _player = std::make_unique<Player>();

    _renderer = std::make_unique<Renderer>(&_renderObjects, &(_player->camera));    
}

void Game::run() {
    bool isRunning = true;
    int fps = 1;
    _renderObjects.push_back(Cube{Texture::DIRT});
    glm::vec3 pos = glm::vec3(0,0,-10);
    _renderObjects[0].setPosition(pos);
    int k = 1;
    sf::Clock clock;
    float velocity = 5.0f;
    sf::Event event;
    sf::Mouse mouse;
    while(isRunning) {

         while (_window->pollEvent(event)) {
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
    
                
        _player->handleMouseMoves(*_window);
        _player->processInput();
        _renderer->render();


        _window->setActive(false);
        _window->display();
        fps +=1;
         if(clock.getElapsedTime().asMilliseconds() > 999) {
             std::cout << k << "\n";
             k = fps;
             fps = 0;

             clock.restart();
         }
    }
    _window->close();
}

