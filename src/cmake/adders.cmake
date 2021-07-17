function(add_static_library LIBRARY_NAME)
	set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
    if (not exists ${SRC_DIR})
        message(FATAL_ERROR "Source directory for '${LIBRARY_NAME}' static library doesn't exist. Should be: ${SRC_DIR}")
    endif()

    set(PUBLIC_HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
    if (not exists ${PUBLIC_HEADERS_DIR})
        message(FATAL_ERROR "Include directory for '${LIBRARY_NAME}' static library doesn't exist. Should be: ${PUBLIC_HEADERS_DIR}")
    endif()

    cmake_parse_arguments(
        PARSED_ARGUMENTS # prefix for inserted variables
        "" # list of names of the boolean arguments (defined are set to true)
        "PUBLIC_HEADERS;PRIVATE_HEADERS;SOURCES;PUBLIC_LIBS;PRIVATE_LIBS" # names of list-valued arguments
        ${ARGN}
    )

    if (not PARSED_ARGUMENTS_SOURCES)
        message(FATAL_ERROR "No source files for static library '${LIBRARY_NAME}' added.")
    endif()

    add_library(${LIBRARY_NAME} STATIC ${PARSED_ARGUMENTS_SOURCES} ${PARSED_ARGUMENTS_PUBLIC_HEADERS} ${PARSED_ARGUMENTS_PRIVATE_HEADERS})

    target_include_directories(${LIBRARY_NAME} PUBLIC ${PARSED_ARGUMENTS_PUBLIC_HEADERS})
    target_include_directories(${LIBRARY_NAME} PRIVATE ${PARSED_ARGUMENTS_PRIVATE_HEADERS})

    if (PARSED_ARGUMENTS_PUBLIC_LIBS)
        target_link_libraries(${LIBRARY_NAME} PUBLIC ${PARSED_ARGUMENTS_PUBLIC_LIBS})
    endif()
    if (PARSED_ARGUMENTS_PRIVATE_LIBS)
        target_link_libraries(${LIBRARY_NAME} PRIVATE ${PARSED_ARGUMENTS_PRIVATE_LIBS})
    endif()
endfunction()
