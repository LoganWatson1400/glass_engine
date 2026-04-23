#pragma once
#include "world/nodes/Node.h"
#include "world/Transform.h"
#include <glm/glm.hpp>

/// @brief A scene node with a full 3D transform (position, rotation, scale).
class Node3D : public Node {
public:
    Transform transform;

    glm::mat4 getWorldTransform() const;

    void translate(glm::vec3 delta) { transform.position    += delta; }
    void rotate(glm::vec3 delta)    { transform.rotation    += delta; }
    void scale(glm::vec3 delta)     { transform.scale       += delta; }
};