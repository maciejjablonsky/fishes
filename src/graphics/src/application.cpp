#include <graphics/application.hpp>

namespace graphics
{
Application::Application(std::string_view title) : _window(title)
{
}
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
    else if (key == GLFW_KEY_F11 && action == GLFW_PRESS)
    {
        auto window_handler = static_cast<Window*>(glfwGetWindowUserPointer(window));
        window_handler->toggle_fullscreen();
    }
}

void Application::run()
{
    glfwSetKeyCallback(_window, key_callback);
    _window.loop();
}
} // namespace graphics
