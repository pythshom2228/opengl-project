#include <SFML/Window/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include "Camera.h"
#include "Time.h"
#include <glm/glm.hpp>
#include <memory>
#include <vector>
#include "Cube.h"

class Player {
public:
    Player();

    ~Player() = default;

    void processInput();

    void handleMouseMoves(const sf::Window& window);

    void setMousePos(sf::Vector2i position);

    void setPosition(glm::vec3 position);

    glm::vec3 getPosition();

    Camera camera;


    float sensitivity = 0.1f;
    

private:
    glm::vec3 _position  = glm::vec3(0.0f,0.0f,0.0f);

    
    std::size_t _cubeId;

    float velocity = 0.5;
    unsigned int hp;
    
    struct Mouse final : sf::Mouse {
    float xpos, ypos;
    float lastX, lastY;
    float xoffset = 0, yoffset = 0;
    } _mouse;
    
    sf::Keyboard _keyboard;
};
