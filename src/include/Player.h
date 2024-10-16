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
    unsigned int hp;

private:
    bool firstMouse = 1;
    float lastX;
    float lastY;

    sf::Mouse _mouse;
    sf::Keyboard _keyboard;
};
