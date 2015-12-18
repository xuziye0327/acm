cmake_minimum_required(VERSION 3.3)
project(5113)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(5113 ${SOURCE_FILES})