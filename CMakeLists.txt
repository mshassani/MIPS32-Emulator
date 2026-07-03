cmake_minimum_required(VERSION 3.15)

project(MIPS)

set(CMAKE_CXX_STANDARD 17)

include_directories(src/memory)

add_executable(memory_test
    test/memory_test.cpp
    src/memory/memory.cpp
)