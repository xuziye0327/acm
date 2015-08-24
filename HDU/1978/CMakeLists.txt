cmake_minimum_required(VERSION 3.2)
project(1978)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(1978 ${SOURCE_FILES})