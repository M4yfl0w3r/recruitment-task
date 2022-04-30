cmake_minimum_required(VERSION 3.22.3)

project(ex1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall")

include_directories(src)

add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(lib)

