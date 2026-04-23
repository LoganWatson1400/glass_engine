#include "Window.h"
#include <GL/glew.h>
#include <cstdio>

bool Window::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init failed: %s\n", SDL_GetError());
        return false;
    }

    // Request OpenGL 3.3 Core Profile
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,   24);

    sdlWindow = SDL_CreateWindow(
        "Glass Engine",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
    );
    if (!sdlWindow) {
        printf("SDL_CreateWindow failed: %s\n", SDL_GetError());
        return false;
    }

    glContext = SDL_GL_CreateContext(sdlWindow);
    if (!glContext) {
        printf("SDL_GL_CreateContext failed: %s\n", SDL_GetError());
        SDL_DestroyWindow(sdlWindow);
        sdlWindow = nullptr;
        return false;
    }

    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        printf("glewInit failed: %s\n", glewGetErrorString(err));
        return false;
    }

    SDL_GL_SetSwapInterval(1); // vsync on

    is_open = true;
    return true;
}

void Window::close()
{
    is_open = false;
    if (glContext)  { SDL_GL_DeleteContext(glContext);  glContext  = nullptr; }
    if (sdlWindow)  { SDL_DestroyWindow(sdlWindow);     sdlWindow  = nullptr; }
    SDL_Quit();
}

bool Window::isOpen() const
{
    return is_open;
}

void Window::poll()
{
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT)
            is_open = false;
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
            is_open = false;
    }
}

void Window::swap()
{
    if (sdlWindow)
        SDL_GL_SwapWindow(sdlWindow);
}
