set(PRJ_NAME math)

set(PRJ_PUBLIC_HEADERS include/${PRJ_NAME}/math.hpp)

utils_add_header_library(${PRJ_NAME} HEADERS ${PRJ_PUBLIC_HEADERS})
