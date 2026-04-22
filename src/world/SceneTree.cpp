#include "SceneTree.h"

GameObject* SceneTree::getRoot()
{
    return &root;
}

void SceneTree::addChild(std::unique_ptr<GameObject> child)
{
    root.addChild(std::move(child));
}