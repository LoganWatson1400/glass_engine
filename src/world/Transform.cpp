#include "world/Transform.h"
#include <glm/gtc/matrix_transform.hpp>

glm::mat4 Transform::toMatrix() const
{
    glm::mat4 m = glm::mat4(1.0f);

    m = glm::translate(m, position);

    // Rotation applied in YXZ order (yaw, pitch, roll)
    m = glm::rotate(m, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    m = glm::rotate(m, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    m = glm::rotate(m, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

    m = glm::scale(m, scale);

    return m;
}