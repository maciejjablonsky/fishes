find_package(fmt REQUIRED)

add_executable(lake_app src/main.cpp)
target_link_libraries(lake_app PUBLIC fmt::fmt graphics)
