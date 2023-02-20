cmake_minimum_required(VERSION 3.22)
project(src)

set(CMAKE_CXX_STANDARD 11)

include_directories(header source)

aux_source_directory(source SRC_LIST)
add_executable(src main.cpp ${SRC_LIST})
