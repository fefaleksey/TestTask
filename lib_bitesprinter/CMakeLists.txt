set(lib_bitesprinter_SRCS
        bitesprinter.h
        bitesprinter.cpp
)

# Declare the library
add_library(lib_bitesprinter STATIC
    ${lib_bitesprinter_SRCS}
)

target_link_libraries(lib_bitesprinter lib_dupsremover)

# Specify here the include directories exported
# by this library
target_include_directories(lib_bitesprinter PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
