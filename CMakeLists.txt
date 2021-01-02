cmake_minimum_required(VERSION 3.15)
project(lox_interpreter)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

add_subdirectory(main)
add_subdirectory(test)
add_subdirectory(lox)
add_subdirectory(common)

