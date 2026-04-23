#include "world/nodes/Node3D.h"

glm::mat4 Node3D::getWorldTransform() const
{
    return transform.toMatrix();
}