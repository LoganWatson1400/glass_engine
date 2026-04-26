#include <catch2/catch_all.hpp>
#include "world/objects/Camera.hh"
#include <glm/glm.hpp>

TEST_CASE("Camera", "[camera]"){

    SECTION("Is a Node3D"){
        Camera camera;
        REQUIRE(dynamic_cast<Node3D*>(&camera) != nullptr);
    }

    SECTION("View matrix changes when it moves") {
        Camera at_origin;
        Camera moved;
        moved.translate({0.0f, 0.0f, 5.0f});
        REQUIRE(at_origin.getViewMatrix() != moved.getViewMatrix());
    }

    SECTION("Projection matrix changes with aspect ratio") {
        Camera camera;
        glm::mat4 wide   = camera.getProjectionMatrix(16.0f / 9.0f);
        glm::mat4 square = camera.getProjectionMatrix(1.0f);
        REQUIRE(wide != square);
    }
}