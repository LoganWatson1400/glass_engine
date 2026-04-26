#include "world/nodes/Node.hh"
#include "world/nodes/Node3D.hh"
#include <catch2/catch_all.hpp>


TEST_CASE("Node", "[node][basic]"){
    SECTION("Can be created"){
        Node node;
        SUCCEED();
    }

    SECTION("Has no parent by default"){
        Node node;
        REQUIRE(node.parent == nullptr);
    }

    SECTION("Has no children by default"){
        Node node;
        REQUIRE(node.children.empty());
    }

    SECTION("Can addChild()"){
        Node parent;
        parent.addChild(std::make_unique<Node>());
        REQUIRE(parent.children.size() == 1);
    }

    SECTION("Child has parent set after addChild()"){
        Node parent;
        parent.addChild(std::make_unique<Node>());
        REQUIRE(parent.children[0]->parent == &parent);
    }

    SECTION("Can be named"){
        Node node;
        node.name = "player";
        REQUIRE(node.name == "player");
    }

    SECTION("onReady() does not crash"){
        Node node;
        REQUIRE_NOTHROW(node.onReady());
    }

    SECTION("onUpdate() does not crash"){
        Node node;
        REQUIRE_NOTHROW(node.onUpdate(0.016f));
    }

}

TEST_CASE("Node3D", "[node][3d]"){
    SECTION("Is a Node"){
        Node3D node;
        REQUIRE(dynamic_cast<Node*>(&node) != nullptr);
    }

    SECTION("Can be created"){
        Node3D node;
        SUCCEED();
    }

    SECTION("Has default position of (0, 0, 0)"){
        Node3D node;
        REQUIRE(node.transform.position == glm::vec3(0.0f, 0.0f, 0.0f));
    }

    SECTION("Has default rotation of (0, 0, 0)"){
        Node3D node;
        REQUIRE(node.transform.rotation == glm::vec3(0.0f, 0.0f, 0.0f));
    }

    SECTION("Has default scale of (1, 1, 1)"){
        Node3D node;
        REQUIRE(node.transform.scale == glm::vec3(1.0f, 1.0f, 1.0f));
    }

    SECTION("translate() moves position by delta"){
        Node3D node;
        node.translate({1.0f, 2.0f, 3.0f});
        REQUIRE(node.transform.position == glm::vec3(1.0f, 2.0f, 3.0f));
    }

    SECTION("rotate() changes rotation by delta"){
        Node3D node;
        node.rotate({45.0f, 0.0f, 0.0f});
        REQUIRE(node.transform.rotation == glm::vec3(45.0f, 0.0f, 0.0f));
    }

    SECTION("scaleBy() changes scale by delta"){
        Node3D node;
        node.scale({1.0f, 1.0f, 1.0f});
        REQUIRE(node.transform.scale == glm::vec3(2.0f, 2.0f, 2.0f));
    }

    SECTION("getWorldTransform() does not crash"){
        Node3D node;
        REQUIRE_NOTHROW(node.getWorldTransform());
    }
}