#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include <glad/glad.h>
#include <SDL2/SDL.h>

#include <graphics_manager.hpp>


void GraphicsManager::initialize()
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
   *  Setup the Vertex Attribute Object
   *  and Vertex Buffer Objects per data
   */

  // Create a Vertex Array Object
  glGenVertexArrays(1, &this->vao);
  glBindVertexArray(this->vao);
  

  // Generate a VBO for position data
  glGenBuffers(1, &this->vbo_pos);

  // Bind to it
  glBindBuffer(GL_ARRAY_BUFFER, this->vbo_pos);
  
  GLsizeiptr sizeof_vbopos_in_bytes =
             static_cast<GLsizeiptr>(vertex_positions.size() * sizeof(GLfloat));

  // Then populate it with the VERTEX POSITION data
  glBufferData(GL_ARRAY_BUFFER,
	       sizeof_vbopos_in_bytes,
	       vertex_positions.data(),
	       GL_STATIC_DRAW);
  
  /*
   *  Enable the attribute in the VAO that refers to what our data is
   *  which is position
   */
  
  // Enable the attribute
  glEnableVertexAttribArray(0);
  
  // Then connect the vbo for pos to the attribute in the vao
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
  

  /*
   * We do the same steps again but for the color data this time
   *
   * - Generate another VBO for colors
   * - Bind to it
   * - Populate it with the color data
   * - Enable the color attribute in the VAO
   * - Then connect the attribute with the color VBO
   */
  glGenBuffers(1, &this->vbo_color);

  glBindBuffer(GL_ARRAY_BUFFER, this->vbo_color);

  GLsizeiptr sizeof_vbocolor_in_bytes =
             static_cast<GLsizeiptr>(vertex_colors.size() * sizeof(GLfloat));

  glBufferData(GL_ARRAY_BUFFER,
	       sizeof_vbocolor_in_bytes,
	       vertex_colors.data(),
	       GL_STATIC_DRAW);
  
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
  

  /*
   *  After setting up the VAO and VBOs
   *  - Unbind from the VAO
   *  - Disable the position and color attributes
   */
  glBindVertexArray(0);
  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
}




void GraphicsManager::create_graphics_pipeline()
{
  std::string vertex_shader_src = load_shader_file("/home/rowan-victor/Projects/cpp/opengl-triangle/shaders/vertex.glsl");
  std::string fragment_shader_src = load_shader_file("/home/rowan-victor/Projects/cpp/opengl-triangle/shaders/fragment.glsl");
  
  //this->compiled_shader_program;
}



std::string GraphicsManager::load_shader_file(const std::string& filepath)
{
  std::ifstream file(filepath);
  
  if(!file.is_open())
  {
    std::cerr << "\n[WARNING]: Failed to load file - " << filepath << std::endl;
    return "";
  }
    

  // Store shader src code loaded from file as string
  std::string shader_src = "";
  
  std::string line;
  while(std::getline(file, line))
  {
    // Make sure to add newline char at end of every line
    shader_src += line + '\n';
  }
  
  std::cout << "[LOG]: File " << filepath << " successfully loaded" << std::endl;
  
  file.close();
  return shader_src;
}


/*
GLuint GraphicsManager::build_shader_program(const std::string& vertex_shader_src, const std::string& fragment_shader_src)
{
   *
   *  This function will compile and link the glsl shader programs
   *  during runtime and return the built shader program
   *
}
*/




void GraphicsManager::pre_draw(){}


void GraphicsManager::draw(){}


void GraphicsManager::render(){}


GLuint GraphicsManager::get_vao() const
{
  return this->vao;
}


GLuint GraphicsManager::get_vbo_pos() const
{
  return this->vbo_pos;
}


GLuint GraphicsManager::get_vbo_color() const
{
  return this->vbo_color;
}
