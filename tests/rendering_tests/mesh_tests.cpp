#include <catch2/catch_all.hpp>
#include "rendering/Mesh.h"

TEST_CASE("Cube mesh has 36 vertices") {
    // 6 faces * 2 triangles * 3 vertices = 36
    Mesh cube = Mesh::makeCube();
    REQUIRE(cube.vertices.size() == 36 * 3); // 3 floats per vertex
}

TEST_CASE("Cube vertices are within unit cube bounds") {
    Mesh cube = Mesh::makeCube();
    for (float v : cube.vertices) {
        REQUIRE(v >= -0.5f);
        REQUIRE(v <=  0.5f);
    }
}
