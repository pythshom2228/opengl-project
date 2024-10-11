#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera {
public:

    Camera();

    ~Camera();

private:
    glm::vec3 cameraPos = glm::vec3(0.0f,0.0f,0.0f);
    glm::vec3 cameraTarget = glm::vec3(0.0f,0.0f,0.0f);
    glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);
    glm::mat4 project;
    glm::mat4 view;
};