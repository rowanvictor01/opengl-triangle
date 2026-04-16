#include <window_manager.hpp>
#include <graphics_manager.hpp>


int main(void)
{
  WindowManager wm("OpenGL Triangle", 800, 600);
  GraphicsManager gm;
  gm.initialize();
  gm.create_graphics_pipeline();
  
  /*
   *  Main Loop
   */
  while(wm.get_is_running())
  {
    wm.poll_window_quit_event();
  }

  return 0;
}
