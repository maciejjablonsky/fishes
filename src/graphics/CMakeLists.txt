set(PRJ_NAME graphics)

set(PRJ_PUBLIC_HEADERS include/${PRJ_NAME}/window.hpp)

set(PRJ_SOURCES src/window.cpp)

set(PRJ_PRIVATE_LIBS glfw3)

add_static_library(
  ${PRJ_NAME}
  PUBLIC_HEADERS
  ${PRJ_PUBLIC_HEADERS}
  SOURCES
  ${PRJ_SOURCES}
  PRIVATE_LIBS
  ${PRJ_PRIVATE_LIBS})
