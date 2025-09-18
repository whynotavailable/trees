cmake_minimum_required(VERSION 4.0)

# Set the project name and version
project(MyProject VERSION 1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Specify the C++ standard (optional, but good practice)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Boost REQUIRED)
add_subdirectory(lib/Catch2)

set(SOURCES
    src/btree.h
)

set(TEST_SOURCES
    src/btree_tests.cpp
)

enable_testing()

add_executable(tests ${TEST_SOURCES} ${SOURCES})
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

