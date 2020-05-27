cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 11)

include_directories(
   ../src
   catch2
)

add_executable(
   test_modifiers
   test_modifiers.cpp
)

target_link_libraries(
   test_modifiers
   mods
)
