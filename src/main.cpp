#include <window_manager.hpp>


int main(void)
{
  WindowManager wm("OpenGL Triangle", 800, 600);
  
  while(wm.get_is_running())
  {
    wm.poll_window_quit_event();
  }

  return 0;
}
