project(Genetics)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB SOURCES
    *.cpp
    *.h
)

add_executable(Genetics ${SOURCES})
