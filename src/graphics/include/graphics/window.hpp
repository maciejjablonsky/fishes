#pragma once

#include <GLFW/glfw3.h>
#include <assert.h>
#include <memory>
#include <optional>
#include <stdexcept>
#include <string_view>

namespace graphics
{
struct GLFW
{
    GLFW()
    {
        if (!glfwInit())
        {
            throw std::runtime_error("Failed to initialize GLFW library");
        }
    }
};

class Window
{
  public:
    enum class Mode : uint8_t
    {
        windowed,
        fullscreen,
        borderless
    };
    static constexpr auto DEFAULT_WIDTH  = 640;
    static constexpr auto DEFAULT_HEIGHT = 480;

  private:
    struct WindowKeeper
    {
        WindowKeeper(GLFWwindow* window_ptr) : window{window_ptr, glfwDestroyWindow}
        {
            assert(window_ptr != nullptr);
        }
        std::unique_ptr<GLFWwindow, decltype(&glfwDestroyWindow)> window;
        operator GLFWwindow*()
        {
            return window.get();
        }
    } _window;

  public:
    Window(std::string_view title, Mode mode = Mode::windowed);
    Window(std::string_view title, size_t width, size_t height, Mode mode = Mode::windowed);

    void run();

  protected:
    auto create_borderless(std::string_view title);
};
} // namespace graphics
