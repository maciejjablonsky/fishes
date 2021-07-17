set(PRJ_NAME fishes_app)

set(PRJ_SOURCES src/main.cpp)

set(PRJ_LIBS graphics)

utils_add_executable(${PRJ_NAME} SOURCES ${PRJ_SOURCES} LIBS ${PRJ_LIBS})
