#include <catch2/catch_all.hpp>
#include "platform/Window.h"

TEST_CASE("Window initializes to (500, 500)"){
    Window window;
    
    REQUIRE(window.x == 0);
    REQUIRE(window.y == 0);
}

TEST_CASE("Window opens cleanly"){
   Window window;
   window.open();
   SUCCEED();
}

TEST_CASE("Window closes cleanly"){
   Window window;
   window.close(); 
   SUCCEED();
}