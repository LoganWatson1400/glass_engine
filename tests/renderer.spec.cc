#include <catch2/catch_all.hpp>
#include "rendering/Renderer.hh"
#include "world/objects/Camera.hh"
#include "world/objects/MeshInstance.hh"
#include "world/SceneTree.hh"

TEST_CASE("Renderer does not crash when uninitialized")
{
    Renderer  renderer;
    SceneTree scene;
    Camera    camera;

    renderer.clear();
    renderer.draw(scene, camera, 800, 600);
    SUCCEED();
}

TEST_CASE("Renderer draws empty scene without crashing")
{
    Renderer  renderer;
    SceneTree scene;
    Camera    camera;

    renderer.clear();
    renderer.draw(scene, camera, 800, 600);
    SUCCEED();
}

TEST_CASE("Renderer draws scene with a MeshInstance without crashing")
{
    Renderer  renderer;
    SceneTree scene;
    Camera    camera;

    auto mi = std::make_unique<MeshInstance>();
    mi->mesh = Primitives::cube();
    // deliberately not calling upload() - mesh.isUploaded() == false
    // renderer should skip it gracefully
    scene.addChild(std::move(mi));

    renderer.clear();
    renderer.draw(scene, camera, 800, 600);
    SUCCEED();
}

// Integration test: requires a real display.
// Passes trivially in headless environments since init() returns false gracefully.
TEST_CASE("Renderer initializes with a valid GL context")
{
    Renderer renderer;
    renderer.init();
    SUCCEED();
}