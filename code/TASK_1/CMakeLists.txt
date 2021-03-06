cmake_minimum_required(VERSION 3.12)
project(TASK_1 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(SOURCE_FILES1 main.c)
add_executable(app1 ${SOURCE_FILES1})