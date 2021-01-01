cmake_minimum_required(VERSION 3.15)
project(lox_interpreter)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

find_package(GTest REQUIRED)
enable_testing()

AUX_SOURCE_DIRECTORY(lox LOX)
AUX_SOURCE_DIRECTORY(common COMMON)
AUX_SOURCE_DIRECTORY(test LOX_TEST)

add_executable(${PROJECT_NAME} main.cpp ${LOX} ${COMMON} ${LOX_TEST})
target_link_libraries(lox_interpreter gtest gtest_main)
add_test(lox_interpreter lox_interpreter)