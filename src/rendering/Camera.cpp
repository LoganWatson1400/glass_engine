#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>

void Camera::move(float dx, float dy, float dz)
{
    x += dx;
    y += dy;
    z += dz;
}

glm::mat4 Camera::getViewMatrix() const
{
    return glm::lookAt(
        glm::vec3(x, y, z),   // eye
        glm::vec3(0, 0, 0),   // look at origin
        glm::vec3(0, 1, 0)    // up
    );
}

glm::mat4 Camera::getProjectionMatrix(float aspectRatio) const
{
    return glm::perspective(
        glm::radians(fov),
        aspectRatio,
        0.1f,    // near plane
        100.0f   // far plane
    );
}
