#pragma once
#include "world/objects/Camera.h"
#include "world/objects/MeshInstance.h"
#include "world/SceneTree.h"
#include "world/nodes/Node.h"
#include "rendering/Mesh.h"
#include "rendering/Shader.h"

class Renderer {
    Shader shader;
    bool   ready = false;

    void drawNode(const Node& node, const Camera& camera, float aspect);

public:
    /// @brief Initialise the renderer. Must be called after a GL context exists.
    bool init();

    /// @brief Release GPU resources. Call before destroying the GL context.
    void shutdown();

    /// @brief Clear the colour and depth buffers.
    void clear();

    /// @brief Draw all visible MeshInstances in the scene from the camera's view.
    /// @param scene    The scene tree to walk.
    /// @param camera   The camera to render from.
    /// @param width    Viewport width in pixels.
    /// @param height   Viewport height in pixels.
    void draw(const SceneTree& scene, const Camera& camera, int width, int height);
};