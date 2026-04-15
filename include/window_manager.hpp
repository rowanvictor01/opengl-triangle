#pragma once

#include <SDL2/SDL.h>
#include <string>


class WindowManager
{
  private:
    SDL_Window* window;
    SDL_Event event;
    SDL_GLContext gl_context;
    int window_width;
    int window_height;
    bool is_running;
  
  public:
    WindowManager(std::string, int, int);
    ~WindowManager();
  
    int get_window_width() const;
    int get_window_height() const;
    void poll_window_quit_event();
    bool get_is_running() const;
};
