cmake_minimum_required(VERSION 3.2)
project(1528)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(1528 ${SOURCE_FILES})