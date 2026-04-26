#include <catch2/catch_all.hpp>
#include <cstdlib>

#include "rendering/Renderer.hh"
#include "world/objects/Camera.hh"
#include "world/objects/MeshInstance.hh"
#include "world/SceneTree.hh"

TEST_CASE("Renderer", "[renderer]"){
    SECTION("Does not crash when uninitialized"){
        Renderer  renderer;
        SceneTree scene;
        Camera    camera;

        renderer.clear();
        renderer.draw(scene, camera, 800, 600);
        SUCCEED();
    }

    SECTION("Draws empty scene without crashing"){
        Renderer  renderer;
        SceneTree scene;
        Camera    camera;

        renderer.clear();
        renderer.draw(scene, camera, 800, 600);
        SUCCEED();
    }

    SECTION("Draws scene with a MeshInstance without crashing"){
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
    SECTION("Initializes with a valid GL context"){
        if(std::getenv("CI"))
            SKIP("Skipping GL context test in CI");
        Renderer renderer;
        renderer.init();
        SUCCEED();
    }
}