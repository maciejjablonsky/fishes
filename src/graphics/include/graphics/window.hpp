#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <assert.h>
#include <glm/vec2.hpp>
#include <memory>
#include <optional>
#include <stdexcept>
#include <string>

namespace lake::graphics
{
struct GLFWInitializer
{
    GLFWInitializer()
    {
        if (!glfwInit())
        {
            throw std::runtime_error("Failed to initialize GLFW library");
        }
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // disable openGL api
    }
};

class Window
{
  private:
    glm::ivec2 position_ = {100, 100};
    glm::ivec2 size_;
    std::pmr::string title_;

    struct window_deleter
    {
        void operator()(GLFWwindow* window)
        {
            if (window)
            {
                glfwDestroyWindow(window);
            }
        }
    };
    std::unique_ptr<GLFWwindow, window_deleter> glfw_window_;
    static_assert(std::is_default_constructible_v<decltype(glfw_window_)>);

  public:
    Window(const std::pmr::string & title, int width, int height);

    inline operator GLFWwindow*()
    {
        return glfw_window_.get();
    }

  protected:
    bool init();
};
} // namespace lake::graphics
