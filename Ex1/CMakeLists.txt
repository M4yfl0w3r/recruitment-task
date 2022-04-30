cmake_minimum_required(VERSION 3.13)

project(ex1)

include(FetchContent)
FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0)
FetchContent_GetProperties(googletest)

if (NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()

add_library(sol STATIC src/Ex1.cpp)

add_executable(sol_run src/main.cpp)
target_link_libraries(sol_run sol)

add_executable(sol_tst tst/Ex1_test.cpp)
target_link_libraries(sol_tst sol gtest_main gmock_main)

