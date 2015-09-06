cmake_minimum_required(VERSION 3.3)
project(753)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(753 ${SOURCE_FILES})