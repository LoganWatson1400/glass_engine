#include "world/SceneTree.hh"

Node* SceneTree::getRoot()
{
    return &root;
}

void SceneTree::addChild(std::unique_ptr<Node> child)
{
    root.addChild(std::move(child));
}

static void updateNode(Node& node, float deltaTime)
{
    node.onUpdate(deltaTime);
    for (auto& child : node.children)
        updateNode(*child, deltaTime);
}

/// @brief Updates all nodes in pre-order
/// @param deltaTime 
void SceneTree::update(float deltaTime)
{
    updateNode(root, deltaTime);
}