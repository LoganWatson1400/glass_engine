#include "engine/Engine.h"

bool Engine::update()
{
    // Return true here (and add game logic) to keep the loop running.
    // Returning false quits after one frame — useful while testing.
    return true;
}

void Engine::run()
{
    if (!window.init())   return; // graceful exit in headless environments
    if (!renderer.init()) return;

    // Pull camera back so the cube is fully visible
    camera.move(0.0f, 0.5f, 3.0f);

    running = true;
    while (running && window.isOpen()) {
        window.poll();
        renderer.clear();
        renderer.draw(camera, window.width, window.height);
        window.swap();
        running = update();
    }

    // Shutdown GL resources BEFORE the context is destroyed
    renderer.shutdown();
    window.close();
}
