#include "world/GameObject.h"
#include "world/SceneTree.h"
#include <catch2/catch_all.hpp>
#include <vector>

TEST_CASE("SceneTree has a root") {
	SceneTree sceneTree;

    SUCCEED();
}

TEST_CASE("SceneTree can addChild()") {
	SceneTree sceneTree;

    sceneTree.addChild(std::make_unique<GameObject>());

    REQUIRE(sceneTree.root.children.size() == 1);
}
