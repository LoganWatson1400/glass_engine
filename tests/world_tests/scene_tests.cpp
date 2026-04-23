#include "world/SceneTree.h"
#include "world/nodes/Node.h"
#include <catch2/catch_all.hpp>

TEST_CASE("SceneTree has a root")
{
    SceneTree sceneTree;
    SUCCEED();
}

TEST_CASE("SceneTree can addChild()")
{
    SceneTree sceneTree;
    sceneTree.addChild(std::make_unique<Node>());
    REQUIRE(sceneTree.root.children.size() == 1);
}

TEST_CASE("SceneTree can addChild() multiple times")
{
    SceneTree sceneTree;
    sceneTree.addChild(std::make_unique<Node>());
    sceneTree.addChild(std::make_unique<Node>());
    sceneTree.addChild(std::make_unique<Node>());
    REQUIRE(sceneTree.root.children.size() == 3);
}

TEST_CASE("SceneTree getRoot() returns root")
{
    SceneTree sceneTree;
    REQUIRE(sceneTree.getRoot() == &sceneTree.root);
}

TEST_CASE("SceneTree update() does not crash with empty tree")
{
    SceneTree sceneTree;
    REQUIRE_NOTHROW(sceneTree.update(0.016f));
}