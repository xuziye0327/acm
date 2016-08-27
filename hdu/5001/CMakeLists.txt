cmake_minimum_required(VERSION 3.2)
project(5001)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(5001 ${SOURCE_FILES})