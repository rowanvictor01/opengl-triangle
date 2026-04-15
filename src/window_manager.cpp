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
  this->quit = false;
}


WindowManager::~WindowManager()
{
  std::cout << "[LOG]: Cleaning up resources..." << std::endl;
  SDL_DestroyWindow(this->window);
  SDL_Quit();
}


/*
WindowManager::get_window_width()
{}
*/


/*
WindowManager::get_window_height()
{}
*/
