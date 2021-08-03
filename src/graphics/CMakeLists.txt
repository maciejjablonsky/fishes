find_package(glm REQUIRED)
find_package(glfw3 REQUIRED)
find_package(Vulkan REQUIRED)
find_package(fmt REQUIRED)
find_package(glad REQUIRED)

add_library(
    graphics STATIC
    include/graphics/window.hpp
    include/graphics/application.hpp
    include/graphics/pipeline.hpp
    include/graphics/cube.hpp
    src/window.cpp
    src/pipeline.cpp
    src/application.cpp
    src/cube.cpp)

target_link_libraries(
    graphics
    PUBLIC Vulkan::Vulkan
           glfw
           glm::glm
           glad::glad
           math
           fmt::fmt)
target_link_libraries(graphics PRIVATE lake::file)
target_include_directories(graphics PUBLIC include)
