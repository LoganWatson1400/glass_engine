#include "world/GameObject.h"

class SceneTree {
public:
    GameObject root;

    void addChild(std::unique_ptr<GameObject> obj) {
        root.addChild(std::move(obj));
    }

    void getChildrenCount(){}
};