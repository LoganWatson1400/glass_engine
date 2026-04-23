#include "rendering/Renderer.h"
#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>
#include <SDL2/SDL.h>

// ---------------------------------------------------------------------------
// Shaders are embedded as raw string literals
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

    cube = Mesh::makeCube();
    cube.upload();

    ready = true;
    return true;
}

void Renderer::shutdown()
{
    cube.free();
    shader.free();
    ready = false;
}

void Renderer::clear()
{
    if (!ready) return;
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::draw(const Camera& camera, int width, int height)
{
    if (!ready) return;

    float aspect = (height > 0) ? (float)width / (float)height : 1.0f;

    // Rotate the cube over time so it's visually obvious it's 3D
    float t     = SDL_GetTicks() / 1000.0f;
    glm::mat4 model = glm::rotate(
        glm::mat4(1.0f),
        t,
        glm::vec3(0.5f, 1.0f, 0.0f)
    );

    shader.use();
    shader.setMat4("model",      model);
    shader.setMat4("view",       camera.getViewMatrix());
    shader.setMat4("projection", camera.getProjectionMatrix(aspect));

    cube.draw();
}
