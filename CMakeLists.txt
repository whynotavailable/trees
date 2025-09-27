cmake_minimum_required(VERSION 4.0)

# Set the project name and version
project(MyProject VERSION 1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Specify the C++ standard (optional, but good practice)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(SOURCES
    src/btree.h
)

set(TEST_SOURCES
    src/btree_tests.cpp
)

set(COVERAGE_FLAGS
    -fprofile-instr-generate
    -fcoverage-mapping
)

add_executable(tests ${TEST_SOURCES} ${SOURCES})
target_compile_options(tests PRIVATE ${COVERAGE_FLAGS})

# Linker flags (critical: ensures libgcov linkage and proper instrumentation)
target_link_options(tests PRIVATE ${COVERAGE_FLAGS})
target_link_libraries(tests GTest::gtest_main)

