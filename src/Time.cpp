#include "include/Time.h"

std::unique_ptr<Time::TimeImpl> Time::_instance = nullptr;

void Time::init() {
    if (Time::_instance == nullptr) {
        Time::_instance = std::make_unique<TimeImpl>();
    }
}

void Time::reset() {
    if(Time::_instance != nullptr) {
        _instance->_estimatedTime.restart();
    }
}

void Time::setDeltaTime() {
    float currentFrame = Time::getEstimatedTime().asSeconds();
    _instance->deltaTime = currentFrame - _instance->lastFrame;
    _instance->lastFrame = currentFrame;
}

float Time::getDeltaTime() {
    return _instance->deltaTime*10;
}

sf::Time Time::getEstimatedTime() {
    return _instance->_estimatedTime.getElapsedTime();
}
