cmake_minimum_required(VERSION 3.19)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp Student.cpp Student.h leetcode/217Solution.cpp)

MESSAGE("CMAKE_CXX_FLAGS IS ${CMAKE_CXX_FLAGS}")
MESSAGE("CMAKE_CXX_FLAGS END")


#set(my_lib_path  ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI})
#set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -L${my_lib_path}")

