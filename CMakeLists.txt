cmake_minimum_required(VERSION 3.20)
project(fishes)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(USE_FOLDERS ON)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(adders)

add_subdirectory(3rd_party)
add_subdirectory(src)
