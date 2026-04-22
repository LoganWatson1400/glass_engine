#pragma once
#include <vector>
#include <memory>

class GameObject
{
public:
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    GameObject* parent = nullptr;

    std::vector<std::unique_ptr<GameObject>> children;

    void addChild(std::unique_ptr<GameObject> child);
    void move(float dx, float dy, float dz);
};