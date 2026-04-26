#include <catch2/catch_all.hpp>
#include "engine/Engine.hh"

TEST_CASE("Engine", "[engine]"){

    SECTION("Starts with running set as true") {
        Engine engine;

        REQUIRE(engine.running == true);
    }

    SECTION("Update can be called without crashing") {
        Engine engine;

        engine.update();

        REQUIRE(engine.running == true);
    }

    SECTION("Run can be called without crashing") {
        Engine engine;

        engine.run();

        SUCCEED();
    }

    // SECTION("updates propogate down the scene tree"){
    //     Engine engine;

    //     auto child = std::make_unique<GameObject>();
    //     GameObject* childPtr = child.get();
    //     engine.scene.addChild(std::move(child));

    //     REQUIRE(engine.update() == true);
    // }
}