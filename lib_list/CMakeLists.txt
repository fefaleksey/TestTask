set(lib_list_SRCS
        list.h
        list.cpp
)

# Declare the library
add_library(lib_list STATIC
    ${lib_list_SRCS}
)

# Specify here the include directories exported
# by this library
target_include_directories(lib_list PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
