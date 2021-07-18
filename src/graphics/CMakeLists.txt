set(PRJ_NAME graphics)

set(PRJ_PUBLIC_HEADERS include/${PRJ_NAME}/window.hpp
                       include/${PRJ_NAME}/application.hpp
                       include/${PRJ_NAME}/cube.hpp
                       )

set(PRJ_SOURCES src/window.cpp src/application.cpp src/cube.cpp)

set(PRJ_PUBLIC_LIBS glfw glm::glm glad math)

utils_add_static_library(
  ${PRJ_NAME}
  PUBLIC_HEADERS
  ${PRJ_PUBLIC_HEADERS}
  SOURCES
  ${PRJ_SOURCES}
  PUBLIC_LIBS
  ${PRJ_PUBLIC_LIBS})
