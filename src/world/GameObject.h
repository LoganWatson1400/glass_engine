#include <iostream>
#include <vector>
#include <memory>

class GameObject {
public:
    float x = 0;
    float y = 0;
    float z = 0;

    GameObject* parent = nullptr;
    int childrenCount = 0;

    std::vector<std::unique_ptr<GameObject>> children;
        
    void addChild(std::unique_ptr<GameObject> child){
        children.push_back(std::move(child));
        child->parent = this;
        childrenCount++;
    }

    void move(float x, float y, float z){}
};