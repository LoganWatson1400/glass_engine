
#ifndef GLASS_ENGINE_ENGINE_HH
#define GLASS_ENGINE_ENGINE_HH

    #include "platform/Window.hh"
    #include "rendering/Renderer.hh"
    #include "world/objects/Camera.hh"
    #include "world/SceneTree.hh"
    #include <SDL2/SDL.h>

    class Engine {
        public:
            Window    window;
            Renderer  renderer;
            Camera    camera;
            SceneTree scene;
            bool      running       = true;
            float     lastDeltaTime = 0.0f;

            void run();
            bool update();

        private:
            float getDeltaTime();
    }; //CLASS Engine

#endif //GLASS_ENGINE_ENGINE_HH