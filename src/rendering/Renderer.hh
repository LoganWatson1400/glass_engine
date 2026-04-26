
#ifndef GLASS_ENGINE_RENDERER_HH
#define GLASS_ENGINE_RENDERER_HH

#include "world/objects/Camera.hh"
#include "world/objects/MeshInstance.hh"
#include "world/SceneTree.hh"
#include "world/nodes/Node.hh"
#include "rendering/Mesh.hh"
#include "rendering/Shader.hh"

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

#endif //GLASS_ENGINE_RENDERER_HH