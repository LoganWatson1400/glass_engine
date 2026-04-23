#include "Mesh.h"

// 6 faces * 2 triangles * 3 vertices = 36 vertices, positions only (x,y,z)
static const float CUBE_VERTS[] = {
    // Front
    -0.5f, -0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,
    // Back
    -0.5f, -0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f,  0.5f, -0.5f,
    // Left
    -0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    // Right
     0.5f,  0.5f,  0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,
    // Top
    -0.5f,  0.5f, -0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f,  0.5f,  0.5f,
    // Bottom
    -0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f, -0.5f,
};

Mesh Mesh::makeCube()
{
    Mesh m;
    m.vertices.assign(CUBE_VERTS, CUBE_VERTS + sizeof(CUBE_VERTS) / sizeof(float));
    return m;
}

void Mesh::upload()
{
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER,
                 vertices.size() * sizeof(float),
                 vertices.data(),
                 GL_STATIC_DRAW);

    // Attribute 0: position (3 floats, no padding)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
}

void Mesh::free()
{
    if (vbo) { glDeleteBuffers(1, &vbo);        vbo = 0; }
    if (vao) { glDeleteVertexArrays(1, &vao);   vao = 0; }
}

void Mesh::draw() const
{
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, (GLsizei)(vertices.size() / 3));
    glBindVertexArray(0);
}
