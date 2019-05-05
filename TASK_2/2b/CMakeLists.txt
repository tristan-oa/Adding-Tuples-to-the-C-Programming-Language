cmake_minimum_required(VERSION 3.12)
project(2b C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(SOURCE_FILES1 testdriver2b.c )
add_executable(2b ${SOURCE_FILES1})
