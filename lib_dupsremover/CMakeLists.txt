set(lib_dupsremover_SRCS
        string_filters.h
        string_filters.cpp
        )

# Declare the library
add_library(lib_dupsremover STATIC
    ${lib_dupsremover_SRCS}
)

# Specify here the include directories exported
# by this library
target_include_directories(lib_dupsremover PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
