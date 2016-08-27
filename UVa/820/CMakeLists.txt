cmake_minimum_required(VERSION 3.3)
project(820)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(820 ${SOURCE_FILES})