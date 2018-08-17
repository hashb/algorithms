cmake_minimum_required(VERSION 2.8)

project(algorithms)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
add_executable(sorting ./src/sorting.cpp)