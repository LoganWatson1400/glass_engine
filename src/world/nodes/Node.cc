#include "world/nodes/Node.hh"

void Node::addChild(std::unique_ptr<Node> child)
{
    child->parent = this;
    children.push_back(std::move(child));
}