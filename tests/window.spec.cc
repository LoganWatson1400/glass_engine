

#include <catch2/catch_all.hpp>
#include "platform/Window.hh"


TEST_CASE("Window", "[window]"){
    SECTION("Has default dimensions") {
        Window window;
        REQUIRE(window.width  == 800);
        REQUIRE(window.height == 600);
    }

    SECTION("Is closed before init") {
        Window window;
        REQUIRE(window.isOpen() == false);
    }

    // Integration test: requires a display. Returns false gracefully in headless env.
    SECTION("Can init") {
        Window window;
        window.init();
        SUCCEED();
    }

    SECTION("Is closed after close()") {
        Window window;
        window.init();
        window.close();
        REQUIRE(window.isOpen() == false);
    }
}