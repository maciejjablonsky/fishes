set(PRJ_NAME fishes_app)

set(PRJ_SOURCES src/main.cpp)

find_package(fmt REQUIRED)

set(PRJ_LIBS graphics fmt::fmt)

utils_add_executable(${PRJ_NAME} SOURCES ${PRJ_SOURCES} LIBS ${PRJ_LIBS})
