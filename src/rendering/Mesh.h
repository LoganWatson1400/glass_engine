#pragma once
#include <vector>
#include <GL/glew.h>

class Mesh {
public:
    std::vector<float> vertices; // flat array: x,y,z per vertex

    GLuint vao = 0;
    GLuint vbo = 0;

    void upload();      // send vertex data to the GPU
    void free();        // release GPU resources (call before GL context destroyed)
    void draw() const;

    static Mesh makeCube();
};
