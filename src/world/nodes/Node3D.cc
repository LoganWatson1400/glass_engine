#include "world/nodes/Node3D.hh"

glm::mat4 Node3D::getWorldTransform() const
{
    return transform.toMatrix();
}