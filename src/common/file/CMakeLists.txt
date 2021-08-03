add_library(file STATIC include/file/io.hpp src/io.cpp)
add_library(
    lake::file
    ALIAS
    file)
target_compile_features(file PUBLIC cxx_std_17)
target_include_directories(file PUBLIC include)
find_package(fmt REQUIRED)
target_link_libraries(file PRIVATE fmt::fmt)
