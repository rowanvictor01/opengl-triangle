#pragma once


class GraphicsManager
{
  private:
    void pre_draw();
    void draw();

  public:
    GraphicsManager();
    ~GraphicsManager();
  
    void initialize();
    void render();
};
