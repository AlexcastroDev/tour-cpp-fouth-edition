cmake_minimum_required(VERSION 3.24)
project(bt_distance)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_FIND_LIBRARY_SUFFIXES ".dylib")
link_directories(/usr/local/lib)

set(SOURCES main.cpp square.cpp square.h)
add_executable(bt_distance ${SOURCES})
include_directories(/usr/local/include)
