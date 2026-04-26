#pragma once
#include "world/nodes/Node.hh"

class SceneTree
{
public:
    Node root;

    /// @brief Returns a pointer to the root node.
    Node* getRoot();

    /// @brief Adds a child node directly under root.
    void addChild(std::unique_ptr<Node> child);

    /// @brief Calls onUpdate on all nodes in the tree.
    /// @param deltaTime Seconds since the last frame.
    void update(float deltaTime);
};