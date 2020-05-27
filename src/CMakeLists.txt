cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 11)

add_library(
   mods 
   modifiers.cpp
   modifiers.h
)

add_executable(
   interview_test
   main.cpp
   Task.h
   BlockingQueue.h
   BlockingQueue.cpp
   modifiers.cpp
   modifiers.h
)
