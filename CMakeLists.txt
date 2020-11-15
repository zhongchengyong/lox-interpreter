cmake_minimum_required(VERSION 3.15)
project(lox_interpreter)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

AUX_SOURCE_DIRECTORY(lox LOX)
AUX_SOURCE_DIRECTORY(common COMMON)

add_executable(lox_interpreter main.cpp ${LOX} ${COMMON})