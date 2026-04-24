#include "rendering/Renderer.h"
#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>

// ---------------------------------------------------------------------------
// Shaders embedded as raw string literals
// ---------------------------------------------------------------------------

static const char* VERT_SRC = R"glsl(
#version 330 core
layout(location = 0) in vec3 aPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}
)glsl";

static const char* FRAG_SRC = R"glsl(
#version 330 core
out vec4 FragColor;

void main()
{
    FragColor = vec4(0.4, 0.7, 1.0, 1.0);  // steel blue
}
)glsl";

// ---------------------------------------------------------------------------

bool Renderer::init()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    if (!shader.compile(VERT_SRC, FRAG_SRC))
        return false;

    ready = true;
    return true;
}

void Renderer::shutdown()
{
    shader.free();
    ready = false;
}

void Renderer::clear()
{
    if (!ready) return;
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::draw(const SceneTree& scene, const Camera& camera, int width, int height)
{
    if (!ready) return;

    float aspect = (height > 0) ? (float)width / (float)height : 1.0f;

    shader.use();
    shader.setMat4("view",       camera.getViewMatrix());
    shader.setMat4("projection", camera.getProjectionMatrix(aspect));

    drawNode(scene.root, camera, aspect);
}

void Renderer::drawNode(const Node& node, const Camera& camera, float aspect)
{
    if (const auto* mi = dynamic_cast<const MeshInstance*>(&node))
    {
        if (mi->visible && mi->mesh.isUploaded())
        {
            shader.setMat4("model", mi->getWorldTransform());
            mi->mesh.draw();
        }
    }

    for (const auto& child : node.children)
        drawNode(*child, camera, aspect);
}