cmake_minimum_required(VERSION 3.21)
project(sem_1)

set(CMAKE_CXX_STANDARD 17)

set(SOLUTION_DIR "solution")
#             ^^^^^^^^ change this directory to test your solution;
#                      also change it in tests.cpp's include

# Set up gtest

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Set up the project

add_executable(
        sem_1
        ${SOLUTION_DIR}/json_parser.cpp
        ${SOLUTION_DIR}/json_parser.h
        tests.cpp
)
target_link_libraries(
        sem_1
        gtest_main
        gmock_main
)
