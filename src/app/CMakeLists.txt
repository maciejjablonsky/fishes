find_package(fmt REQUIRED)

add_executable(fishes_app src/main.cpp)
target_link_libraries(fishes_app PUBLIC fmt::fmt graphics)
