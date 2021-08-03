#pragma once

#include <graphics/window.hpp>
#include <graphics/pipeline.hpp>

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
    graphics::Pipeline pipeline_{"../../../shaders/simple_shader.vert.spv",
                                 "../../../shaders/simple_shader.frag.spv"};

  public:
    void run();
};
} // namespace lake
