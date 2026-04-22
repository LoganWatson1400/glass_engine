#pragma once

#include "config/config.h"

class Window {
public:
    int x = DEFAULT_WINDOW_WIDTH;
    int y = DEFAULT_WINDOW_HEIGHT;
    bool is_open = true;

    void open();
    void close();
    bool isOpen();
    void poll();
};
