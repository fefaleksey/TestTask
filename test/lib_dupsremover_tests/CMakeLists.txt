file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(lib_dupsremover_tests ${SRCS})

TARGET_LINK_LIBRARIES(lib_dupsremover_tests
    lib_dupsremover
    libgtest
)

add_test(NAME lib_dupsremover_tests
         COMMAND lib_dupsremover_tests)
