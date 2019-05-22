cmake_minimum_required(VERSION 3.8)
project(ValidateBinarySearchTree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES  library.cpp library.h)
add_executable(ValidateBinarySearchTree ${SOURCE_FILES})