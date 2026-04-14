#pragma once

#include <SDL2/SDL.h>
#include <string>


class WindowManager
{
  private:
    SDL_Window* window;
    SDL_GLContext gl_context;
    int window_width;
    int window_height;
    bool quit;
  
  public:
    WindowManager(std::string, int, int);
    ~WindowManager();
  
    int get_window_width();
    int get_window_height();
};
