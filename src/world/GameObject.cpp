#include "GameObject.h"

void GameObject::addChild(std::unique_ptr<GameObject> child)
{
    child->parent = this;
    children.push_back(std::move(child));
}

void GameObject::move(float dx, float dy, float dz)
{
    x += dx;
    y += dy;
    z += dz;
}