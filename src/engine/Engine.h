#pragma once
#include "platform/Window.h"
#include "rendering/Renderer.h"
#include "rendering/Camera.h"
#include "world/SceneTree.h"

class Engine {
public:
    Window    window;
    Renderer  renderer;
    Camera    camera;
    SceneTree scene;
    bool      running = true;

    void run();
    bool update();  // return true to keep loop alive, false to quit
};
