#include "include/Player.h"
#include <iostream>

Player::Player() : hp(100)/*, _currentLookingCube(lookingAt())*/{
    _mouse.xpos = _mouse.getPosition().x;
    _mouse.ypos = _mouse.getPosition().y;
    _mouse.lastX = _mouse.xpos;
    _mouse.lastY = _mouse.ypos;
}

void Player::update(const sf::Window& window,std::vector<Cube>& _cubes) {
   // lookingAt(_cubes);
    processInput(_cubes);
    handleMouseMoves(window);
}

// Cube& Player::lookingAt(std::vector<Cube>& _cubes) {
    
// }

void Player::processInput(std::vector<Cube>& _cubes) {
    static sf::Clock putTiming;
    if(_mouse.isButtonPressed(sf::Mouse::Right)) {
        if(putTiming.getElapsedTime().asMilliseconds() > 300){
            this->putCube(_cubes);
            putTiming.restart();
        }
    
    }

    if(_mouse.isButtonPressed(Player::Mouse::Left)) {
        // if(this->_cubeDestructionProgress > 100)
           //  _currentLookingCube.get().~Cube();
 
     } else {this->_cubeDestructionProgress = 0;}


     
    if(_keyboard.isKeyPressed(sf::Keyboard::Num1))
        _currentHoldingCube = _quickInventory[0];

    else if(_keyboard.isKeyPressed(sf::Keyboard::Num2))
        _currentHoldingCube = _quickInventory[1];

    else if(_keyboard.isKeyPressed(sf::Keyboard::Num3))
        _currentHoldingCube = _quickInventory[2];

    else if(_keyboard.isKeyPressed(sf::Keyboard::Num4))
        _currentHoldingCube = _quickInventory[3];

    else if(_keyboard.isKeyPressed(sf::Keyboard::Num5))
        _currentHoldingCube = _quickInventory[4];

    else if(_keyboard.isKeyPressed(sf::Keyboard::Num6))
        _currentHoldingCube = _quickInventory[5];

    else if(_keyboard.isKeyPressed(sf::Keyboard::Num7))
        _currentHoldingCube = _quickInventory[6];

    else if(_keyboard.isKeyPressed(sf::Keyboard::Num8))
        _currentHoldingCube = _quickInventory[7];

    else if(_keyboard.isKeyPressed(sf::Keyboard::Num9))
        _currentHoldingCube = _quickInventory[8];







    float dvelocity = velocity * Time::getDeltaTime();
    if(_keyboard.isKeyPressed(sf::Keyboard::W)) {
        _position += dvelocity * glm::vec3(
            camera.cameraFront.x / cos(glm::radians(camera.pitch)),0,camera.cameraFront.z / cos(glm::radians(camera.pitch))
            );
        camera.cameraPos = _position;
    }
    if(_keyboard.isKeyPressed(sf::Keyboard::S)) {
        _position -= dvelocity * glm::vec3(
            camera.cameraFront.x / cos(glm::radians(camera.pitch)),0,camera.cameraFront.z / cos(glm::radians(camera.pitch))
            );
        camera.cameraPos = _position;
    }
    if(_keyboard.isKeyPressed(sf::Keyboard::A)) {
        _position -= glm::normalize(glm::cross(camera.cameraFront, camera.cameraUp)) * dvelocity;
        camera.cameraPos = _position;
    }
    if(_keyboard.isKeyPressed(sf::Keyboard::D)) {
        _position += glm::normalize(glm::cross(camera.cameraFront, camera.cameraUp)) * dvelocity;
        camera.cameraPos = _position;    
    }
    if(_keyboard.isKeyPressed(sf::Keyboard::Space)) {
        _position += dvelocity * camera.cameraUp;
        camera.cameraPos = _position;
    }
    if(_keyboard.isKeyPressed(sf::Keyboard::LShift)){
        _position -= dvelocity * camera.cameraUp;
        camera.cameraPos = _position;
    }

}

const Cube::types& Player::getCurrentHoldingCube() {
    return _currentHoldingCube;
}

void Player::setMousePos(sf::Vector2i _position) {
    _mouse.setPosition(_position);
}

void Player::handleMouseMoves(const sf::Window& window) {
    _mouse.xpos = _mouse.getPosition().x;
    _mouse.ypos = _mouse.getPosition().y;

    _mouse.xoffset = _mouse.xpos - _mouse.lastX;
    _mouse.yoffset = _mouse.lastY - _mouse.ypos;

    
    _mouse.xoffset *= sensitivity * Time::getDeltaTime();
    _mouse.yoffset *= sensitivity * Time::getDeltaTime();

    camera.yaw += _mouse.xoffset;
    camera.pitch += _mouse.yoffset;

    if(camera.pitch > 89.0f)
        camera.pitch =  89.0f;
    if(camera.pitch < -89.0f)
        camera.pitch = -89.0f;

    camera.direction.x = cos(glm::radians(camera.yaw)) * cos(glm::radians(camera.pitch));
    camera.direction.y = sin(glm::radians(camera.pitch));
    camera.direction.z = sin(glm::radians(camera.yaw)) * cos(glm::radians(camera.pitch));
    camera.cameraFront = glm::normalize(camera.direction);

    _mouse.setPosition(window.getPosition() + sf::Vector2i(window.getSize().x/2,window.getSize().y/2));
    _mouse.lastX = _mouse.getPosition().x;
    _mouse.lastY = _mouse.getPosition().y;
}

void Player::setPosition(glm::vec3 position) {
    this->_position = position;
    this->camera.cameraPos = position;
}

glm::vec3 Player::getPosition() {
    return _position;
}

//TODO доработать
void Player::putCube(std::vector<Cube>& _cubes) {
    static const std::uint32_t cubePittingDistance = 2;
    auto pos = this->getPosition() + 
    glm::vec3(
        camera.cameraFront.x*cubePittingDistance,
        camera.cameraFront.y*cubePittingDistance,
        camera.cameraFront.z*cubePittingDistance
    );

    _cubes.emplace_back(this->getCurrentHoldingCube());
    _cubes.back().setPosition(
        glm::vec3(std::round(pos.x),std::round(pos.y),std::round(pos.z))
    );
}