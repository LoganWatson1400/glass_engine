#pragma once
#include "GameObject.h"

class SceneTree
{
public:
    GameObject root;

    GameObject* getRoot();
    void addChild(std::unique_ptr<GameObject> child);
};