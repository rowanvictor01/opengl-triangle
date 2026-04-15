#include <iostream>
#include <vector>

#include <glad/glad.h>
#include <SDL2/SDL.h>

#include <graphics_manager.hpp>



GraphicsManager::GraphicsManager(){}


GraphicsManager::~GraphicsManager(){}


bool GraphicsManager::initialize()
{
  /*
   * Load Glad
   * Then Glad loads all OpenGL functions
   */
  if(!gladLoadGLLoader(SDL_GL_GetProcAddress))
  {
    std::cerr << "Failed to initialize glad" << std::endl;
    exit(1);
  }
  
  /*
   *  Vertex Specification
   *  - Defines the vertices' position, color, and other data
   */
  const std::vector<GLfloat> vertex_positions
  {
    -0.8f, -0.8f, 0.f,  // vertex 1
    0.8f, -0.8f, 0.f,   // vertex 2
    0.f, 0.8f, 0.f      // vertex 3
  };
  
  const std::vector<GLfloat> vertex_colors
  {
    1.f, 0.f, 0.f,  // vertex 1
    0.f, 1.f, 0.f,  // vertex 2
    0.f, 0.f, 1.f   // vertex 3
  };
  
  
  /*
   * Returns a bool value to signify
   * if initialization was successfull
   */
  return true;
}


void GraphicsManager::pre_draw(){}


void GraphicsManager::draw(){}


void GraphicsManager::render(){}
