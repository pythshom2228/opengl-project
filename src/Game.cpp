#include "include/Game.h"
#include "include/Renderer.h"
#include "include/Player.h" 


struct Game::_Impl {
    std::vector<Cube> _renderObjects;
    std::unique_ptr<Player> _player;
    std::unique_ptr<Renderer>   _renderer;
};


Game::Game() : _pImpl(std::make_unique<_Impl>()) {
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
    _pImpl->_player = std::make_unique<Player>();

    _pImpl->_renderer = std::make_unique<Renderer>(&_pImpl->_renderObjects, &(_pImpl->_player->camera));

    Time::init();  
}

Game::~Game() {}

void Game::run() {
    _pImpl->_player->setMousePos(_window->getPosition() + sf::Vector2i(_window->getSize().x/2,_window->getSize().y/2));
    _window->setActive(1);
    bool isRunning = true;
    int fps = 1;
    _pImpl->_renderObjects.emplace_back(Cube::GRASS);
    sf::Clock clock;
    sf::Event event;
    _pImpl->_player->setPosition(glm::vec3(-4,2,0));
    _pImpl->_renderObjects[0].popRenderSide(Cube::top);
    
    
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
        
        Time::setDeltaTime();


        _pImpl->_player->handleMouseMoves(*_window);
        _pImpl->_player->processInput();
        _pImpl->_renderer->render();


        _window->setActive(false);
        _window->display();

        fps += 1;
        if(clock.getElapsedTime().asMilliseconds() > 999) {
            std::cout << "FPS: " << fps << "\n";
            fps=0;

            clock.restart();
        }
        
    }

    _window->close();
}

