
#ifndef GLASS_ENGINE_WINDOW_HH
#define GLASS_ENGINE_WINDOW_HH

    #ifndef GLASS_ENGINE_CONFIG_HH
        #include "config.hh"
    #endif

    #include <SDL2/SDL.h>

    class Window {
        public:
            int  height  = DEFAULT_WINDOW_HEIGHT;
            int  width   = DEFAULT_WINDOW_WIDTH;
            bool is_open = false;

            bool init();        // create window + GL context; returns false on failure
            void close();
            bool isOpen() const;
            void poll();        // process OS events (sets is_open=false on quit/Escape)
            void swap();        // swap front/back buffers

        private:
            SDL_Window*   sdlWindow = nullptr;
            SDL_GLContext glContext  = nullptr;
    }; //CLASS Window

#endif //GLASS_ENGINE_WINDOW_HH