cmake_minimum_required(VERSION 3.22)
project(hoffman)

set(CMAKE_CXX_STANDARD 14)

add_executable(hoffman main.cpp lz78.cpp lz78.h)
