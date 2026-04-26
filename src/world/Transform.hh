
#ifndef GLASS_ENGINE_TRANSFORM_HH
#define GLASS_ENGINE_TRANSFORM_HH

#include <glm/glm.hpp>

struct Transform
{
    glm::vec3 position = {0.0f, 0.0f, 0.0f};
    glm::vec3 rotation = {0.0f, 0.0f, 0.0f};
    glm::vec3 scale    = {1.0f, 1.0f, 1.0f};

    glm::mat4 toMatrix() const;
};

#endif //GLASS_ENGINE_TRANSFORM_HH