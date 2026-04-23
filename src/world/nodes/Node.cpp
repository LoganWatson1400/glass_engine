#include "world/nodes/Node.h"

void Node::addChild(std::unique_ptr<Node> child)
{
    child->parent = this;
    children.push_back(std::move(child));
}