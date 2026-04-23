#include "world/SceneTree.h"

Node* SceneTree::getRoot()
{
    return &root;
}

void SceneTree::addChild(std::unique_ptr<Node> child)
{
    root.addChild(std::move(child));
}

void SceneTree::update(float deltaTime)
{
    // TODO: walk tree recursively and call onUpdate(deltaTime) on each node
}