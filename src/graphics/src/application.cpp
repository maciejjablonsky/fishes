#include <graphics/application.hpp>

namespace lake
{
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

void Application::run()
{
    glfwSetKeyCallback(window_, key_callback);
    while (!window_.should_close())
    {
        glfwPollEvents();
    }
}
} // namespace lake
