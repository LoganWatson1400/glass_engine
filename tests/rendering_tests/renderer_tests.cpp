#include <catch2/catch_all.hpp>
#include "rendering/Renderer.h"

TEST_CASE("Renderer clears screen"){
    Renderer renderer;

    renderer.clear();

    SUCCEED();
}

TEST_CASE("Renderer draws a cube"){
    Renderer renderer;

    renderer.draw();

    SUCCEED();
}