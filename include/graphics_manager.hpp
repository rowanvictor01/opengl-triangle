#pragma once

#include <glad/glad.h>


class GraphicsManager
{
  private:
    GLuint vao;  // Vertex Array Object
    GLuint vbo_pos;  // Vertex Buffer Object for the vertices' positions
    GLuint vbo_color;  // Vertex Buffer Object for the vertices' colors

    void pre_draw();
    void draw();

  public:
    void initialize();
    void render();
  
    // Getters
    GLuint get_vao() const;
    GLuint get_vbo_pos() const;
    GLuint get_vbo_color() const;
};
