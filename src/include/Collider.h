#include <glm/glm.hpp>
#include <array>

class Collider {
public:

    Collider(const std::array<std::int32_t,2> scale);

    void update(const glm::vec3  vertexPos);

    bool checkIfCollides(const Collider& other) const;

private:
    const std::array<std::int32_t,2> _scale;
};
