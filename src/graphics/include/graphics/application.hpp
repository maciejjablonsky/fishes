#pragma once

#include <graphics/window.hpp>

namespace graphics
{
class Application
{
  private:
    GLFWInitializer glfw_initializer;
    Window _window;
  public:
    Application(std::string_view app_title = "Unnamed app");
    void run();
    
  protected:
    void toggle_fullscreen();
};
} // namespace graphics
