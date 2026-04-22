#include "Window.h"

void Window::open()
{
    is_open = true;
}

void Window::close()
{
    is_open = false;
}

bool Window::isOpen()
{
    return is_open;
}