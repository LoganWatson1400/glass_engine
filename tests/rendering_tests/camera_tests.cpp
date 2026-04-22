#include <catch2/catch_all.hpp>
#include <rendering/Camera.h>

TEST_CASE("Camera starts at origin"){
    Camera camera;

    REQUIRE(camera.x == 0);
    REQUIRE(camera.y == 0);
    REQUIRE(camera.z == 0);
}