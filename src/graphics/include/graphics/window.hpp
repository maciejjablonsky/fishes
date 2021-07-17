#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <assert.h>
#include <glm/vec2.hpp>
#include <memory>
#include <optional>
#include <stdexcept>
#include <string_view>
namespace graphics
{
struct GLFWInitializer
{
    GLFWInitializer()
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
    glm::ivec2 _position      = {100, 100};
    glm::ivec2 _size          = {DEFAULT_WIDTH, DEFAULT_HEIGHT};
    Mode _mode                = Mode::windowed;
    GLFWmonitor* _monitor = nullptr;
    std::unique_ptr<GLFWwindow, decltype(&glfwDestroyWindow)> _window;

  public:
    Window(std::string_view title, Mode mode = Mode::windowed);
    Window(std::string_view title, size_t width, size_t height, Mode mode = Mode::windowed);

    inline operator GLFWwindow*()
    {
        return _window.get();
    }

    void loop();
    bool is_fullscreen() const;
    void toggle_fullscreen();
  private:
    void update_position_and_size();
};
} // namespace graphics
