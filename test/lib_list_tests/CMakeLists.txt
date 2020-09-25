file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(lib_list_tests ${SRCS})

TARGET_LINK_LIBRARIES(lib_list_tests
    lib_list
    libgtest
)

add_test(NAME lib_list_tests
         COMMAND lib_list_tests)
