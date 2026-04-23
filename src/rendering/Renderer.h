#pragma once
#include "rendering/Camera.h"
#include "rendering/Mesh.h"
#include "rendering/Shader.h"

class Renderer {
    Shader shader;
    Mesh   cube;
    bool   ready = false;
public:
    bool init();
    void shutdown();        // call before GL context is destroyed
    void clear();
    void draw(const Camera& camera, int width, int height);
};