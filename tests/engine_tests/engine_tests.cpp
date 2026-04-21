#include <catch2/catch_all.hpp>
#include "engine/Engine.h"

TEST_CASE("Engine starts with running = true") {
    Engine engine;

    REQUIRE(engine.running == true);
}

TEST_CASE("Engine update can be called without crashing") {
    Engine engine;

    engine.update();

    REQUIRE(engine.running == true);
}

TEST_CASE("Engine run can be called without crashing") {
    Engine engine;

    engine.run();

    SUCCEED();
}