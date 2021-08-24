cmake_minimum_required(VERSION 3.19)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp Student.cpp Student.h leetcode/217.cpp leetcode/53.cpp leetcode/1.cpp leetcode/88.cpp leetcode/350.cpp leetcode/121.cpp leetcode/566.cpp leetcode/118.cpp leetcode/36.cpp leetcode/73.cpp leetcode/387.cpp leetcode/383.cpp leetcode/242.cpp leetcode/141.cpp leetcode/21.cpp leetcode/203.cpp leetcode/206.cpp leetcode/83.cpp leetcode/20.cpp leetcode/232.cpp leetcode/144.cpp leetcode/102.cpp leetcode/104.cpp leetcode/101.cpp leetcode/226.cpp leetcode/112.cpp leetcode/700.cpp leetcode/701.cpp leetcode/avl_tree.cpp leetcode/98.cpp leetcode/653.cpp)

MESSAGE("CMAKE_CXX_FLAGS IS ${CMAKE_CXX_FLAGS}")
MESSAGE("CMAKE_CXX_FLAGS END")


#set(my_lib_path  ${CMAKE_SOURCE_DIR}/libs/${ANDROID_ABI})
#set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -L${my_lib_path}")

