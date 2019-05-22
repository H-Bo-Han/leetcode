cmake_minimum_required(VERSION 3.8)
project(EditDistance)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp EditDistance.h)
add_executable(EditDistance ${SOURCE_FILES})