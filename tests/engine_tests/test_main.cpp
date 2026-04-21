#include <catch2/catch_all.hpp>

TEST_CASE("basic test")
{
    REQUIRE(1 == 1);
}

// ── Basic assertions ──────────────────────────────────────────────────────────
TEST_CASE("basic math")
{
    REQUIRE(1 + 1 == 3);        // fails loudly, stops the test
    CHECK(2 * 3 == 6);          // fails but keeps running
}

// ── Sections (shared setup, separate paths) ───────────────────────────────────
TEST_CASE("vector operations")
{
    std::vector<int> v = {1, 2, 3};   // runs fresh for each SECTION

    SECTION("size is correct")
    {
        REQUIRE(v.size() == 3);
    }

    SECTION("push_back adds an element")
    {
        v.push_back(4);
        REQUIRE(v.size() == 4);
        REQUIRE(v.back() == 4);
    }

    SECTION("pop_back removes last element")
    {
        v.pop_back();
        REQUIRE(v.size() == 2);
    }
}

// ── Tags (lets you run subsets of tests) ─────────────────────────────────────
TEST_CASE("string handling", "[strings]")
{
    std::string s = "hello";
    REQUIRE(s.length() == 5);
    REQUIRE(s + " world" == "hello world");
}

// ── Exceptions ────────────────────────────────────────────────────────────────
TEST_CASE("exceptions", "[exceptions]")
{
    REQUIRE_THROWS(throw std::runtime_error("oops"));
    REQUIRE_THROWS_AS(throw std::invalid_argument("bad"), std::invalid_argument);
    REQUIRE_NOTHROW([]{}());
}