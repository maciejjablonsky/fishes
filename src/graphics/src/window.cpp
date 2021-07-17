#include <graphics/window.hpp>

namespace graphics
{
Window::Window(std::string_view title, Mode mode) : Window(title, DEFAULT_WIDTH, DEFAULT_HEIGHT, mode)
{
}
auto Window::create_borderless(std::string_view title)
{
    const auto monitor = glfwGetPrimaryMonitor();
    auto mode          = glfwGetVideoMode(monitor);
    glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
    return glfwCreateWindow(mode->width, mode->height, title.data(), monitor, nullptr);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

Window::Window(std::string_view title, size_t width, size_t height, Mode mode)
    : _window([&]() -> GLFWwindow* {
          switch (mode)
          {
          case Mode::windowed:
              return glfwCreateWindow(width, height, title.data(), nullptr, nullptr);
          case Mode::fullscreen:
              return glfwCreateWindow(width, height, title.data(), glfwGetPrimaryMonitor(), nullptr);
          case Mode::borderless:
              return create_borderless(title);
          default:
              return nullptr;
          }
      }())
{
    glfwSetKeyCallback(_window, &key_callback);
}

void Window::run()
{
    while (!glfwWindowShouldClose(_window))
    {
        glfwSwapBuffers(_window);
        glfwPollEvents();
    }
}

} // namespace graphics
