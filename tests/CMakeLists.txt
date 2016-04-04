cmake_minimum_required(VERSION 3.2)
project(tests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

file(GLOB SOURCES
    *.cpp
    *.h
)

add_executable(tests ${SOURCES})
include_directories("../gtest")
target_link_libraries(tests gtest pthread)
