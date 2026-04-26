#include <catch2/catch_all.hpp>
#include "rendering/Mesh.hh"

TEST_CASE("Mesh", "[mesh]"){
    SECTION("Primitives::cube() has 36 vertices"){
        // 6 faces * 2 triangles * 3 vertices = 36
        Mesh cube = Primitives::cube();
        REQUIRE(cube.vertices.size() == 36 * 3); // 3 floats per vertex
    }

    SECTION("Primitives::cube() vertices are within unit cube bounds"){
        Mesh cube = Primitives::cube();
        for (float v : cube.vertices){
            REQUIRE(v >= -0.5f);
            REQUIRE(v <=  0.5f);
        }
    }

    SECTION("Primitives::plane() has 6 vertices"){
        // 1 face * 2 triangles * 3 vertices = 6
        Mesh plane = Primitives::plane();
        REQUIRE(plane.vertices.size() == 6 * 3);
    }

    SECTION("Mesh is not uploaded by default"){
        Mesh mesh = Primitives::cube();
        REQUIRE(mesh.isUploaded() == false);
    }
}