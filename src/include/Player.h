#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include "Camera.h"
#include <glm/glm.hpp>

class Player {
public:
    Player();

    ~Player() = default;

    void processInput();


    Camera camera;

    glm::vec3 position  = glm::vec3(0.0f,0.0f,0.0f);

    unsigned int hp;

private:
    sf::Keyboard _keyboard;
    sf::Mouse _mouse;
};
