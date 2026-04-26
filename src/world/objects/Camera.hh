#pragma once
#include "world/nodes/Node3D.hh"
#include <glm/glm.hpp>

class Camera : public Node3D {
public:
    float fov = 45.0f;

    glm::mat4 getViewMatrix() const;
    glm::mat4 getProjectionMatrix(float aspectRatio) const;
};
