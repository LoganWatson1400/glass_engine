#include <catch2/catch_all.hpp>
#include "rendering/Camera.h"
#include <glm/glm.hpp>

TEST_CASE("Camera starts at origin") {
    Camera camera;
    REQUIRE(camera.x == 0.0f);
    REQUIRE(camera.y == 0.0f);
    REQUIRE(camera.z == 0.0f);
}

TEST_CASE("Camera move updates position") {
    Camera camera;
    camera.move(1.0f, 2.0f, 3.0f);
    REQUIRE(camera.x == 1.0f);
    REQUIRE(camera.y == 2.0f);
    REQUIRE(camera.z == 3.0f);
}

TEST_CASE("Camera view matrix changes when camera moves") {
    Camera at_origin;
    Camera moved;
    moved.move(0.0f, 0.0f, 5.0f);
    REQUIRE(at_origin.getViewMatrix() != moved.getViewMatrix());
}

TEST_CASE("Camera projection matrix changes with aspect ratio") {
    Camera camera;
    glm::mat4 wide   = camera.getProjectionMatrix(16.0f / 9.0f);
    glm::mat4 square = camera.getProjectionMatrix(1.0f);
    REQUIRE(wide != square);
}
