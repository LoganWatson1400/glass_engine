#include "world/SceneTree.hh"
#include "world/nodes/Node.hh"
#include <catch2/catch_all.hpp>
// #include <vector>
// #include <string>

struct SpyNode : public Node {
    std::string id;
    std::vector<std::string>* log;
    float lastDelta = 0.0f;

    SpyNode(std::string id, std::vector<std::string>* log) 
        : id(id), log(log) {}

    void onUpdate(float deltaTime) override {
        lastDelta = deltaTime;
        log->push_back(id);
    }
};

TEST_CASE("SceneTree", "[scenetree]"){
    SECTION("Has a root")
    {
        SceneTree sceneTree;
        SUCCEED();
    }

    SECTION("Can addChild()")
    {
        SceneTree sceneTree;
        sceneTree.addChild(std::make_unique<Node>());
        REQUIRE(sceneTree.root.children.size() == 1);
    }

    SECTION("Can addChild() multiple times")
    {
        SceneTree sceneTree;
        sceneTree.addChild(std::make_unique<Node>());
        sceneTree.addChild(std::make_unique<Node>());
        sceneTree.addChild(std::make_unique<Node>());
        REQUIRE(sceneTree.root.children.size() == 3);
    }

    SECTION("getRoot() returns root")
    {
        SceneTree sceneTree;
        REQUIRE(sceneTree.getRoot() == &sceneTree.root);
    }

    SECTION("update() does not crash with empty tree")
    {
        SceneTree sceneTree;
        REQUIRE_NOTHROW(sceneTree.update(0.016f));
    }

    SECTION("Calls onUpdate on a child node")
    {
        SceneTree scene;
        std::vector<std::string> log;

        scene.addChild(std::make_unique<SpyNode>("a", &log));
        scene.update(0.016f);

        REQUIRE(log.size() == 1);
        REQUIRE(log[0] == "a");
    }

    SECTION("Calls onUpdate on all children")
    {
        SceneTree scene;
        std::vector<std::string> log;

        scene.addChild(std::make_unique<SpyNode>("a", &log));
        scene.addChild(std::make_unique<SpyNode>("b", &log));
        scene.addChild(std::make_unique<SpyNode>("c", &log));
        scene.update(0.016f);

        REQUIRE(log.size() == 3);
    }

    SECTION("Update traversal is pre-order (parent before child)")
    {
        SceneTree scene;
        std::vector<std::string> log;

        auto parent = std::make_unique<SpyNode>("parent", &log);
        parent->addChild(std::make_unique<SpyNode>("child", &log));
        scene.addChild(std::move(parent));

        scene.update(0.016f);

        REQUIRE(log.size() == 2);
        REQUIRE(log[0] == "parent");
        REQUIRE(log[1] == "child");
    }

    SECTION("Update traversal visits deeply nested nodes")
    {
        SceneTree scene;
        std::vector<std::string> log;

        auto a = std::make_unique<SpyNode>("a", &log);
        auto b = std::make_unique<SpyNode>("b", &log);
        b->addChild(std::make_unique<SpyNode>("c", &log));
        a->addChild(std::move(b));
        scene.addChild(std::move(a));

        scene.update(0.016f);

        REQUIRE(log.size() == 3);
        REQUIRE(log[0] == "a");
        REQUIRE(log[1] == "b");
        REQUIRE(log[2] == "c");
    }

    SECTION("Passes deltaTime correctly to nodes")
    {
        SceneTree scene;
        std::vector<std::string> log;

        auto spy = std::make_unique<SpyNode>("a", &log);
        SpyNode* ptr = spy.get();
        scene.addChild(std::move(spy));

        scene.update(0.032f);

        REQUIRE(ptr->lastDelta == Catch::Approx(0.032f));
    }

    SECTION("Does not call onUpdate when tree is empty")
    {
        SceneTree scene;
        REQUIRE_NOTHROW(scene.update(0.016f));
    }
}
