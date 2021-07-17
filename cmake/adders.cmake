function(utils_add_static_library LIBRARY_NAME)
	set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
    if (NOT EXISTS ${SRC_DIR})
        message(FATAL_ERROR "Source directory for '${LIBRARY_NAME}' static library doesn't exist. Should be: ${SRC_DIR}")
    endif()

    set(PUBLIC_HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
    if (NOT EXISTS ${PUBLIC_HEADERS_DIR})
        message(FATAL_ERROR "Include directory for '${LIBRARY_NAME}' static library doesn't exist. Should be: ${PUBLIC_HEADERS_DIR}")
    endif()
    if (NOT EXISTS ${PUBLIC_HEADERS_DIR}/${LIBRARY_NAME})
        message(FATAL_ERROR "Library '${LIBRARY_NAME}' doesn't export public headers under include/lib_name path. Should be '${PUBLIC_HEADERS_DIR}/${LIBRARY_NAME}'")
    endif()

    cmake_parse_arguments(
        PARSED_ARGUMENTS # prefix for inserted variables
        "" # list of names of the boolean arguments (defined are set to true)
        "" # mono valued arguments
        "PUBLIC_HEADERS;PRIVATE_HEADERS;SOURCES;PUBLIC_LIBS;PRIVATE_LIBS" # names of list-valued arguments
        ${ARGN}
    )

    if (NOT PARSED_ARGUMENTS_SOURCES)
        message(FATAL_ERROR "No source files for static library '${LIBRARY_NAME}' added.")
    endif()

    add_library(${LIBRARY_NAME} STATIC ${PARSED_ARGUMENTS_SOURCES} ${PARSED_ARGUMENTS_PUBLIC_HEADERS} ${PARSED_ARGUMENTS_PRIVATE_HEADERS})

    target_include_directories(${LIBRARY_NAME} PUBLIC ${PUBLIC_HEADERS_DIR})

    if (PARSED_ARGUMENTS_PUBLIC_LIBS)
        target_link_libraries(${LIBRARY_NAME} PUBLIC ${PARSED_ARGUMENTS_PUBLIC_LIBS})
    endif()
    if (PARSED_ARGUMENTS_PRIVATE_LIBS)
        target_link_libraries(${LIBRARY_NAME} PRIVATE ${PARSED_ARGUMENTS_PRIVATE_LIBS})
    endif()
endfunction()

function(utils_add_executable EXECUTABLE_NAME)
	set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
    if (NOT EXISTS ${SRC_DIR})
        message(FATAL_ERROR "Source directory for '${EXECUTABLE_NAME}' executable doesn't exist. Should be: ${SRC_DIR}")
    endif()

    cmake_parse_arguments(
        PARSED_ARGUMENTS # prefix for inserted variables
        "" # list of names of the boolean arguments (defined are set to true)
        "" # mono valued arguments
        "SOURCES;LIBS" # names of list-valued arguments
        ${ARGN}
    )

    if (NOT PARSED_ARGUMENTS_SOURCES)
        message(FATAL_ERROR "No source files for executable '${EXECUTABLE_NAME}' added.")
    endif()

    add_executable(${EXECUTABLE_NAME} ${PARSED_ARGUMENTS_SOURCES})

    if (PARSED_ARGUMENTS_LIBS)
        target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${PARSED_ARGUMENTS_LIBS})
    endif()
endfunction()
