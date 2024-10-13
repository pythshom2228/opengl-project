#include "include/Player.h"
#include <iostream>

Player::Player() {
    hp = 100;
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