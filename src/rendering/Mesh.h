#pragma once
#include <vector>
#include <GL/glew.h>

/// @brief GPU mesh resource. Upload once, draw many times.
/// Owns VAO/VBO call free() before GL context is destroyed.
class Mesh {
public:
    std::vector<float> vertices;
    GLuint vao = 0;
    GLuint vbo = 0;

    /// @brief Upload vertex data to the GPU.
    void upload();

    /// @brief Release GPU resources.
    void free();

    /// @brief Draw the mesh. Requires upload() to have been called first.
    void draw() const;

    /// @brief Returns true if the mesh has been uploaded to the GPU.
    bool isUploaded() const { return vao != 0; }
};

/// @brief primitive meshes.
namespace Primitives {
    Mesh cube();
    Mesh plane();
    Mesh sphere();
}