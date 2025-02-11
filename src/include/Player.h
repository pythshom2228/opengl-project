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
    enum gameMode {
        SURVIVAL = 0,
        CREATIVE
    } gamemode;

    Player();

    ~Player() = default;

    void update(const sf::Window& window,std::vector<Cube>& _cube);


    void setMousePos(sf::Vector2i position);

    void setPosition(glm::vec3 position);

    const Cube::types& getCurrentHoldingCube();

    glm::vec3 getPosition();

    Camera camera;


    float sensitivity = 1.0f;
    

private:
    glm::vec3 lookVector = this->getPosition() + glm::vec3(camera.cameraFront.x*3,camera.cameraFront.y*3,camera.cameraFront.z*3);

    Cube& lookingAt(std::vector<Cube>& _cubes);

    void processInput(std::vector<Cube>& _cubes);
    void handleMouseMoves(const sf::Window& window);

    void putCube(std::vector<Cube>& _cubes);
    void destructCube();

    std::uint8_t _cubeDestructionProgress = 0;  

    std::array<Cube::types, 9> _quickInventory = {
        Cube::types::DIRT,
        Cube::types::GRASS,
        Cube::types::COBBLESTONE,
        Cube::types::PLANKS,
        Cube::types::NONE,
        Cube::types::NONE,
        Cube::types::NONE,
        Cube::types::NONE,
        Cube::types::NONE
    };
    //std::reference_wrapper<Cube> _currentLookingCube;

    Cube::types _currentHoldingCube = _quickInventory[0];

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
