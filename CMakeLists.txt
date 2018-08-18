cmake_minimum_required(VERSION 2.8)

project(algorithms)

set(CMAKE_CXX_STANDARD 11)

add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)

include_directories(include)

add_executable(sorting ./src/sorting.cpp)
add_executable(searching ./src/searching.cpp)
