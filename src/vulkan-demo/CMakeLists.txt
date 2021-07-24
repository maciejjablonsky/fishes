set(PRJ_NAME vulkan-demo)

find_package(Vulkan REQUIRED FATAL_ERROR)


utils_add_executable(${PRJ_NAME}
    SOURCES src/main.cpp
    LIBS  Vulkan::Vulkan glfw glm
)
