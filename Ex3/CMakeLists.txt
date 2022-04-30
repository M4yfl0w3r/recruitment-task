cmake_minimum_required(VERSION 3.13)

project(ex3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall")

include(FetchContent)
FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0)
FetchContent_GetProperties(googletest)

if (NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()

add_executable(sol_run src/main.cpp)

add_executable(sol_tst tst/Ex3_test.cpp)
target_link_libraries(sol_tst gtest_main gmock_main)

