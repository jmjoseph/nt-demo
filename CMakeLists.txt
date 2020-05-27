cmake_minimum_required(VERSION 3.12)

project(interview_test)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

add_subdirectory(src) 


include(CTest)

if(BUILD_TESTING)
   add_subdirectory(test)
endif()
