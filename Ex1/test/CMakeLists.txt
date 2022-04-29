cmake_minimum_required(VERSION 3.22.3)

set (This Tests)

set (Sources 
  Ex1_test.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
  gtest_main
  main
)

add_test(
  NAME ${This}
  COMMAND ${This}
)

