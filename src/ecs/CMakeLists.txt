find_package(EnTT REQUIRED)

add_library(
    ecs STATIC
    include/${PRJ_NAME}/entity.hpp include/${PRJ_NAME}/scene.hpp
    include/${PRJ_NAME}/components.hpp src/entity.cpp src/scene.cpp
    src/components.cpp)

target_link_libraries(ecs PUBLIC EnTT)
