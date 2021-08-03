cmake_minimum_required(VERSION 3.20)
project(fishes)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(adders)

include(${CMAKE_BINARY_DIR}/conan_paths.cmake OPTIONAL)

add_subdirectory(src)
