cmake_minimum_required(VERSION 3.2)
project(4081)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -o2 -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(4081 ${SOURCE_FILES})