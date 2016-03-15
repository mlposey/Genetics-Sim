cmake_minimum_required(VERSION 3.2)
project(Genetics)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB SOURCES
    genetics.cpp
    ./*/*.cpp
    ./*/*.h
)

add_executable(Genetics ${SOURCES})
