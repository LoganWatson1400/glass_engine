#pragma once
#include "platform/Window.h"
#include "rendering/Renderer.h"
#include "world/objects/Camera.h"
#include "world/SceneTree.h"
#include <SDL2/SDL.h>

class Engine {
public:
    Window    window;
    Renderer  renderer;
    Camera    camera;
    SceneTree scene;
    bool      running       = true;
    float     lastDeltaTime = 0.0f;

    void run();
    bool update();

private:
    float getDeltaTime();
};