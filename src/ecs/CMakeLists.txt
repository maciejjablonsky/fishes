set(PRJ_NAME ecs)

set(PRJ_PUBLIC_HEADERS
	include/${PRJ_NAME}/entity.hpp
	include/${PRJ_NAME}/scene.hpp
	include/${PRJ_NAME}/components.hpp
)

set(PRJ_SOURCES
	src/entity.cpp
	src/scene.cpp
	src/components.cpp
)

find_package(EnTT REQUIRED)

set(PRJ_PUBLIC_LIBS EnTT)

utils_add_static_library(ecs PUBLIC_HEADERS ${PRJ_PUBLIC_HEADERS} SOURCES ${PRJ_SOURCES} PUBLIC_LIBS ${PRJ_PUBLIC_LIBS})
