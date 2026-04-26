#include <catch2/catch_all.hpp>

TEST_CASE("Main", "[main]"){

    SECTION("Health check") REQUIRE(1 == 1);
}