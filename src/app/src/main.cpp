#include <graphics/window.hpp>

int main()
{
    graphics::GLFW glfw;
    graphics::Window window("title yay", graphics::Window::Mode::windowed);
    window.run();
}
