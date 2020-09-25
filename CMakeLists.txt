cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 11)

project(TestTask)

enable_testing()

add_subdirectory(main)
add_subdirectory(test)
add_subdirectory(lib_dupsremover)
add_subdirectory(lib_bitesprinter)
add_subdirectory(lib_list)
