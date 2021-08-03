#pragma once

#include <graphics/window.hpp>

namespace lake
{
class Application
{
  public:
    static constexpr int DEFAULT_WIDTH  = 800;
    static constexpr int DEFAULT_HEIGHT = 600;

  private:
    graphics::GLFWInitializer glfw_initializer_;
    graphics::Window window_{"Lake", DEFAULT_WIDTH, DEFAULT_HEIGHT};

  public:
    void run();
};
} // namespace lake
