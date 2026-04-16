#pragma once

#include <string>

#include <glad/glad.h>


class GraphicsManager
{
  private:
    GLuint vao;  // Vertex Array Object
    GLuint vbo_pos;  // Vertex Buffer Object for the vertices' positions
    GLuint vbo_color;  // Vertex Buffer Object for the vertices' colors
  
    GLuint compiled_shader_program;

    std::string load_shader_file(const std::string&);
    GLuint build_shader_program(const std::string&, const std::string&);

    void pre_draw();
    void draw();

  public:
    void initialize();
    void create_graphics_pipeline();
    void render();
  
    // Getters
    GLuint get_vao() const;
    GLuint get_vbo_pos() const;
    GLuint get_vbo_color() const;
};
