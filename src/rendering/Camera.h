#pragma once
#include <glm/glm.hpp>

class Camera {
public:
    float x   = 0.0f;
    float y   = 0.0f;
    float z   = 0.0f;
    float fov = 45.0f;

    void move(float dx, float dy, float dz);

    glm::mat4 getViewMatrix() const;
    glm::mat4 getProjectionMatrix(float aspectRatio) const;
};
