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
    _window->setFramerateLimit(60);
    _renderer = std::make_unique<Renderer>(&_renderObjects);

}

void Game::run() {
    bool isRunning = true;
    _renderObjects = {Cube{},Cube{.position=glm::vec3(0.5,0,0)},Cube{.position=glm::vec3(1,0,0)}};
    int fps = 1;
    int k = 1;
    sf::Clock clock;
    float velocity = 5.0f;
    while(isRunning) {
        sf::Event event;   
        sf::Keyboard keyboard;
        sf::Mouse mouse;
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
            velocity = 5.0f;
            if(keyboard.isKeyPressed(sf::Keyboard::Space)) {
                velocity = 10.f;
            }
        for(auto& cube : _renderObjects) {

            if(keyboard.isKeyPressed(sf::Keyboard::W)) {
                cube.position.y += velocity/k;
            }
            if(keyboard.isKeyPressed(sf::Keyboard::S)) {
                cube.position.y -= velocity/k;
            }
            
            if(keyboard.isKeyPressed(sf::Keyboard::A)) {
                cube.position.x -= velocity/k;
            }

            if(keyboard.isKeyPressed(sf::Keyboard::D)) {
                cube.position.x += velocity/k;
            }
            if(keyboard.isKeyPressed(sf::Keyboard::R)) {
                cube.position.z -= velocity/k;
            }

            if(keyboard.isKeyPressed(sf::Keyboard::T)) {
                cube.position.z +=velocity/k;
            }
            if(keyboard.isKeyPressed(sf::Keyboard::C)) {
               cube.rotation = glm::rotate(_renderObjects[0].rotation,glm::radians(120.0f/k),glm::vec3(1.0f,1.0f,1.0f));
            }
        }
        _renderer->render();
        fps += 1;

        _window->display();

        if(clock.getElapsedTime().asMilliseconds() > 999) {
            std::cout << k << "\n";
            k = fps;
            fps = 0;

            clock.restart();
        }
    }
    _window->close();
}

