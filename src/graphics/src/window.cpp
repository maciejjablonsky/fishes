#include <graphics/window.hpp>
#include <fmt/format.h>

namespace lake::graphics
{
Window::Window(const std::pmr::string& title, int width, int height) : title_(title), size_{width, height}
{
    if(!init())
    {
        throw std::runtime_error(fmt::format("Failed to initialize widow: {}", title)); 
    }
}

[[nodiscard]] bool Window::init()
{
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    if (auto window = glfwCreateWindow(size_[0], size_[1], title_.c_str(), nullptr, nullptr))
    {
        glfw_window_.reset(window);
        return true;
    }
    return false;
}
} // namespace lake::graphics
