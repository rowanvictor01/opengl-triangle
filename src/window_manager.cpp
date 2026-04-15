#include <iostream>

#include <window_manager.hpp>


WindowManager::WindowManager(std::string title, int width, int height)
{
  // Initialize SDL2
  if(SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cerr << "SDL2 could not initialize video subsystem" << std::endl;
    exit(1);
  }

  // Set SDL OpenGL context attributes
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
		      SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

  // Create SDL window
  this->window = SDL_CreateWindow(title.c_str(), 0, 0, width, height, SDL_WINDOW_OPENGL);

  // Check if window was created successfully 
  if(this->window == nullptr)
  {
    std::cerr << "Failed to create SDL window" << std::endl;
    exit(1);
  }

  // Create OpenGL context
  this->gl_context = SDL_GL_CreateContext(this->window);

  // Check if context was created successfully
  if(this->gl_context == nullptr)
  {
    std::cerr << "Failed to create OpenGL context through SDL2" << std::endl;
    exit(1);
  }
  
  this->window_width = width;
  this->window_height = height;
  this->is_running = true;
}


WindowManager::~WindowManager()
{
  std::cout << "[LOG]: Cleaning up resources..." << std::endl;
  SDL_DestroyWindow(this->window);
  SDL_Quit();
}


/*
 * Handles setting of the is_running flag when user presses the 'x'
 * button to close the window
*/
void WindowManager::poll_window_quit_event()
{
  while(SDL_PollEvent(&this->event) != 0)
  {
    if(this->event.type == SDL_QUIT)
    {
      std::cout << "[LOG]: Exiting Program..." << std::endl;
      this->is_running = false;
      break;
    }
  }
}


bool WindowManager::get_is_running() const
{
  return this->is_running;
}


/*
WindowManager::get_window_width() const
{}
*/


/*
WindowManager::get_window_height() const
{}
*/
