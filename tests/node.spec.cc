#include "world/nodes/Node.hh"
#include "world/nodes/Node3D.hh"
#include <catch2/catch_all.hpp>

// ---------------------------------------------------------------------------
// Node
// ---------------------------------------------------------------------------

TEST_CASE("Node can be created")
{
    Node node;
    SUCCEED();
}

TEST_CASE("Node has no parent by default")
{
    Node node;
    REQUIRE(node.parent == nullptr);
}

TEST_CASE("Node has no children by default")
{
    Node node;
    REQUIRE(node.children.empty());
}

TEST_CASE("Node can addChild()")
{
    Node parent;
    parent.addChild(std::make_unique<Node>());
    REQUIRE(parent.children.size() == 1);
}

TEST_CASE("Node child has parent set after addChild()")
{
    Node parent;
    parent.addChild(std::make_unique<Node>());
    REQUIRE(parent.children[0]->parent == &parent);
}

TEST_CASE("Node can be named")
{
    Node node;
    node.name = "player";
    REQUIRE(node.name == "player");
}

TEST_CASE("Node onReady() does not crash")
{
    Node node;
    REQUIRE_NOTHROW(node.onReady());
}

TEST_CASE("Node onUpdate() does not crash")
{
    Node node;
    REQUIRE_NOTHROW(node.onUpdate(0.016f));
}

// ---------------------------------------------------------------------------
// Node3D
// ---------------------------------------------------------------------------
TEST_CASE("Node3D is a Node")
{
    Node3D node;
    REQUIRE(dynamic_cast<Node*>(&node) != nullptr);
}

TEST_CASE("Node3D can be created")
{
    Node3D node;
    SUCCEED();
}

TEST_CASE("Node3D has default position of (0, 0, 0)")
{
    Node3D node;
    REQUIRE(node.transform.position == glm::vec3(0.0f, 0.0f, 0.0f));
}

TEST_CASE("Node3D has default rotation of (0, 0, 0)")
{
    Node3D node;
    REQUIRE(node.transform.rotation == glm::vec3(0.0f, 0.0f, 0.0f));
}

TEST_CASE("Node3D has default scale of (1, 1, 1)")
{
    Node3D node;
    REQUIRE(node.transform.scale == glm::vec3(1.0f, 1.0f, 1.0f));
}

TEST_CASE("Node3D translate() moves position by delta")
{
    Node3D node;
    node.translate({1.0f, 2.0f, 3.0f});
    REQUIRE(node.transform.position == glm::vec3(1.0f, 2.0f, 3.0f));
}

TEST_CASE("Node3D rotate() changes rotation by delta")
{
    Node3D node;
    node.rotate({45.0f, 0.0f, 0.0f});
    REQUIRE(node.transform.rotation == glm::vec3(45.0f, 0.0f, 0.0f));
}

TEST_CASE("Node3D scaleBy() changes scale by delta")
{
    Node3D node;
    node.scale({1.0f, 1.0f, 1.0f});
    REQUIRE(node.transform.scale == glm::vec3(2.0f, 2.0f, 2.0f));
}

TEST_CASE("Node3D getWorldTransform() does not crash")
{
    Node3D node;
    REQUIRE_NOTHROW(node.getWorldTransform());
}