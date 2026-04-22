#include <catch2/catch_all.hpp>
#include "world/GameObject.h"

TEST_CASE("GameObject starts at origin"){
    GameObject obj;

    REQUIRE(obj.x == 0);
    REQUIRE(obj.y == 0);
    REQUIRE(obj.z == 0);
}

TEST_CASE("GameObject can addChild()") {
	GameObject obj;

    obj.addChild(std::make_unique<GameObject>());

    REQUIRE(obj.children.size() == 1);
}

TEST_CASE("GameObject child's parent gets assigned"){
    GameObject obj;

    obj.addChild(std::make_unique<GameObject>());

    REQUIRE(obj.children.at(0)->parent == &obj);
}

TEST_CASE("GameObject can move(x,y,z)"){
    GameObject obj;

    obj.move(1,1,1);
    REQUIRE(obj.x == 1);
    REQUIRE(obj.y == 1);
    REQUIRE(obj.z == 1);
}