#include <SFML/Window/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include "Camera.h"
#include <glm/glm.hpp>

class Player {
public:
    Player();

    ~Player() = default;

    void processInput();

    void handleMouseMoves(const sf::Window& window);


    Camera camera;

    glm::vec3 position  = glm::vec3(0.0f,0.0f,0.0f);
    float sensitivity = 0.1f;

private:
    float velocity;
    unsigned int hp;
    
    struct Mouse final : sf::Mouse {
    float xpos, ypos;
    float lastX, lastY;
    float xoffset = 0, yoffset = 0;
    } _mouse;

    sf::Keyboard _keyboard;
};
