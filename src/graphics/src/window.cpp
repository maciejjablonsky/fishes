#include <graphics/window.hpp>

namespace graphics
{
Window::Window(std::string_view title, Mode mode) : Window(title, DEFAULT_WIDTH, DEFAULT_HEIGHT, mode)
{
}
inline bool Window::is_fullscreen() const
{
    return _mode == Mode::borderless;
}

void Window::toggle_fullscreen()
{
    if (!is_fullscreen())
    {
        update_position_and_size();

        const auto* mode = glfwGetVideoMode(_monitor);
        glfwWindowHint(GLFW_RED_BITS, mode->redBits);
        glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
        glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
        glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
        glfwSetWindowMonitor(_window.get(), _monitor, 0, 0, mode->width, mode->height, mode->refreshRate);

        _mode = Mode::borderless;
    }
    else
    {
        glfwSetWindowMonitor(_window.get(), nullptr, _position[0], _position[1], _size[0], _size[1], 0);
        _mode = Mode::windowed;
    }
}

namespace detail
{

auto create_borderless(std::string_view title)
{
    const auto monitor = glfwGetPrimaryMonitor();
    auto mode          = glfwGetVideoMode(monitor);
    glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
    return glfwCreateWindow(mode->width, mode->height, title.data(), monitor, nullptr);
}

GLFWwindow* create_window(std::string_view title, size_t width, size_t height, Window::Mode mode)
{
    switch (mode)
    {
    case Window::Mode::windowed:
        return glfwCreateWindow(width, height, title.data(), nullptr, nullptr);
    case Window::Mode::fullscreen:
        return glfwCreateWindow(width, height, title.data(), glfwGetPrimaryMonitor(), nullptr);
    case Window::Mode::borderless:
        return create_borderless(title);
    default:
        return nullptr;
    }
}
} // namespace detail

Window::Window(std::string_view title, size_t width, size_t height, Mode mode)
    : _window(
          [&] {
              if (auto window = detail::create_window(title, width, height, mode))
              {
                  glfwMakeContextCurrent(window);
                  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
                  {
                      throw std::runtime_error("Failed to load OpenGL symbols");
                  }
                  glViewport(0, 0, width, height);
                  glfwSetWindowUserPointer(window, this);
                  glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) {
                      glViewport(0, 0, width, height);
                  });
                  _monitor = glfwGetPrimaryMonitor();
                  glfwGetWindowSize(window, &_size[0], &_size[1]);
                  glfwGetWindowPos(window, &_position[0], &_position[1]);
                  return window;
              }
              glfwTerminate();
              throw std::runtime_error("Failed to initialize window.");
          }(),
          glfwDestroyWindow)
{
    update_position_and_size();
}

void Window::loop()
{
    while (!glfwWindowShouldClose(_window.get()))
    {
        glfwSwapBuffers(_window.get());
        glfwPollEvents();
    }
}

void Window::update_position_and_size()
{
    glfwGetWindowSize(_window.get(), &_size[0], &_size[1]);
    glfwGetWindowPos(_window.get(), &_position[0], &_position[1]);
}

} // namespace graphics
