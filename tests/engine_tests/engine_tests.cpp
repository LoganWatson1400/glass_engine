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

// TEST_CASE("Engine updates propogate down the scene tree"){
//     Engine engine;

//     auto child = std::make_unique<GameObject>();
//     GameObject* childPtr = child.get();
//     engine.scene.addChild(std::move(child));

//     REQUIRE(engine.update() == true);
// }