#include <SFML/Window.hpp>
#include <memory>

class Time {
public:

    Time() = delete;

    static void init();

    static sf::Time getEstimatedTime();

    static void setDeltaTime();

    static float getDeltaTime();
    
private:
    static void reset();
    

    struct TimeImpl {
        float deltaTime = 0.0f;
        float lastFrame = 0.0f; 

        sf::Clock _estimatedTime;
    };

    static std::unique_ptr<TimeImpl> _instance;
};