#include "include/Player.h"
#include <iostream>

Player::Player() : hp(100) {
    _mouse.xpos = _mouse.getPosition().x;
    _mouse.ypos = _mouse.getPosition().y;
    _mouse.lastX = _mouse.xpos;
    _mouse.lastY = _mouse.ypos;
}

void Player::processInput() {
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
    if(_mouse.isButtonPressed(Player::Mouse::Left)) {
        
    }
}

void Player::setMousePos(sf::Vector2i _position) {
    _mouse.setPosition(_position);
}

void Player::handleMouseMoves(const sf::Window& window) {
    _mouse.xpos = _mouse.getPosition().x;
    _mouse.ypos = _mouse.getPosition().y;

    _mouse.xoffset = _mouse.xpos - _mouse.lastX;
    _mouse.yoffset = _mouse.lastY - _mouse.ypos;

    
    _mouse.xoffset *= sensitivity;
    _mouse.yoffset *= sensitivity;

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