#include "world/SceneTree.h"

class Engine{
public:
    SceneTree scene;
    bool running = true;

    void run();
    void update();

};