#include "engine/Engine.hh"
#include "world/objects/MeshInstance.hh"
#include "rendering/Mesh.hh"

float Engine::getDeltaTime()
{
    static Uint64 last = SDL_GetPerformanceCounter();
    Uint64 now    = SDL_GetPerformanceCounter();
    float  dt     = (float)(now - last) / (float)SDL_GetPerformanceFrequency();
    last          = now;
    lastDeltaTime = dt;
    return dt;
}

bool Engine::update()
{
    if (!scene.root.children.empty())
    {
        if (auto* mi = dynamic_cast<MeshInstance*>(scene.root.children[0].get()))
        {
            mi->rotate({22.5f * lastDeltaTime, 45.0f * lastDeltaTime, 0.0f});
        }
    }
    return true;
}

void Engine::run()
{
    if (!window.init())   return;
    if (!renderer.init()) return;

    camera.transform.position = {0.0f, 0.5f, 3.0f};

    auto cube = std::make_unique<MeshInstance>();
    cube->name = "cube";
    cube->mesh = Primitives::cube();
    cube->mesh.upload();
    scene.addChild(std::move(cube));

    running = true;
    while (running && window.isOpen())
    {
        float dt = getDeltaTime();
        window.poll();
        scene.update(dt);
        renderer.clear();
        renderer.draw(scene, camera, window.width, window.height);
        window.swap();
        running = update();
    }

    renderer.shutdown();
    window.close();
}