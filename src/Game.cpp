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
    _renderObjects.push_back(Cube{.position=glm::vec3(0,0,-10)});
    int fps = 1;
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
    
        if(mouse.isButtonPressed(sf::Mouse::Button::Left) && clock.getElapsedTime().asSeconds() >= 1) {
            glm::vec3 front = _player->camera.cameraFront;
            _renderObjects.push_back(Cube{.position=_player->position+(glm::vec3(front.x*2,front.y,front.z*2))});
            clock.restart();
        }

        
        _player->handleMouseMoves(*_window);
        _player->processInput();
        _renderer->render();

        fps += 1;

        _window->setActive(false);
        _window->display();

        // if(clock.getElapsedTime().asMilliseconds() > 999) {
        //     //std::cout << k << "\n";
        //     k = fps;
        //     fps = 0;

        //     clock.restart();
        // }
    }
    _window->close();
}

