#pragma once


class GraphicsManager
{
  private:
    void pre_draw();
    void draw();

  public:
    GraphicsManager();
    ~GraphicsManager();
  
    bool initialize();
    void render();
};
