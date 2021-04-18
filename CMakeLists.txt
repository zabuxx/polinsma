cmake_minimum_required(VERSION 3.1)

project(shapes)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

add_executable(shapes main.cpp shapes.cpp)


