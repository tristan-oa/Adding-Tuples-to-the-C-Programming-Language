cmake_minimum_required(VERSION 3.12)
project(2a C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(SOURCE_FILES1 testdriver2a.c)
add_executable(2a ${SOURCE_FILES1})
