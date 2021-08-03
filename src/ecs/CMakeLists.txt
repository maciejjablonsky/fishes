find_package(EnTT REQUIRED)

add_library(
    ecs STATIC
    include/ecs/components.hpp
    include/ecs/entity.hpp
    include/ecs/scene.hpp
    src/components.cpp
    src/entity.cpp
    src/scene.cpp)

target_link_libraries(ecs PUBLIC EnTT)
