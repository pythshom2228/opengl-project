#include "include/Player.h"
#include <iostream>

Player::Player() : hp(100) {
    _mouse.xpos = _mouse.getPosition().x;
    _mouse.ypos = _mouse.getPosition().y;
    _mouse.lastX = _mouse.xpos;
    _mouse.lastY = _mouse.ypos;
}

void Player::processInput() {
    if(_keyboard.isKeyPressed(sf::Keyboard::W)) {
        position += camera.cameraSpeed * camera.cameraFront;
        camera.cameraPos = position;
    }
    if(_keyboard.isKeyPressed(sf::Keyboard::S)) {
        position -= camera.cameraSpeed * camera.cameraFront;
        camera.cameraPos = position;
    }
    if(_keyboard.isKeyPressed(sf::Keyboard::A)) {
        position -= glm::normalize(glm::cross(camera.cameraFront, camera.cameraUp)) * camera.cameraSpeed;
        camera.cameraPos = position;
    }
    if(_keyboard.isKeyPressed(sf::Keyboard::D)) {
        position += glm::normalize(glm::cross(camera.cameraFront, camera.cameraUp)) * camera.cameraSpeed;
        camera.cameraPos = position;    
    }
    if(_keyboard.isKeyPressed(sf::Keyboard::Space)) {
        position += camera.cameraSpeed * camera.cameraUp;
        camera.cameraPos = position;
    }
    if(_keyboard.isKeyPressed(sf::Keyboard::LShift)){
        position -= camera.cameraSpeed * camera.cameraUp;
        camera.cameraPos = position;
    }
    if(_keyboard.isKeyPressed(sf::Keyboard::C)) {

    }
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
