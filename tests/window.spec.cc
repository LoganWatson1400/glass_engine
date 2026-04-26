

#include <catch2/catch_all.hpp>
#include "platform/Window.hh"

TEST_CASE("Window has default dimensions") {
    Window window;
    REQUIRE(window.width  == 800);
    REQUIRE(window.height == 600);
}

TEST_CASE("Window is closed before init") {
    Window window;
    REQUIRE(window.isOpen() == false);
}

// Integration test: requires a display. Returns false gracefully in headless env.
TEST_CASE("Window can init") {
    Window window;
    window.init();
    SUCCEED();
}

TEST_CASE("Window is closed after close()") {
    Window window;
    window.init();
    window.close();
    REQUIRE(window.isOpen() == false);
}
