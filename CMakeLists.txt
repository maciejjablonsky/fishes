cmake_minimum_required(VERSION 3.20)
project(lake)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(${CMAKE_BINARY_DIR}/conan_paths.cmake OPTIONAL)

add_subdirectory(src)
