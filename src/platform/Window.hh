#pragma once
#include <SDL2/SDL.h>

class Window {
    SDL_Window*   sdlWindow = nullptr;
    SDL_GLContext glContext  = nullptr;
public:
    int  width   = 800;
    int  height  = 600;
    bool is_open = false;

    bool init();        // create window + GL context; returns false on failure
    void close();
    bool isOpen() const;
    void poll();        // process OS events (sets is_open=false on quit/Escape)
    void swap();        // swap front/back buffers
};
