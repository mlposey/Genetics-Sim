cmake_minimum_required(VERSION 3.7)
project(src)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
INCLUDE_DIRECTORIES(src external)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        src/core/gene/Gene.cpp
        src/core/gene/Gene.h
        src/core/gene/GeneFactory.cpp
        src/core/gene/GeneFactory.h
        src/core/gene/MasterGene.cpp
        src/core/gene/MasterGene.h
        src/core/gene/MasterGeneIndex.cpp
        src/core/gene/MasterGeneIndex.h
        src/core/Allele.cpp
        src/core/Allele.h
        src/core/Chromosome.cpp
        src/core/Chromosome.h
        src/core/ChromosomeFactory.cpp
        src/core/ChromosomeFactory.h
        src/core/Organism.cpp
        src/core/Organism.h
        src/core/OrganismFactory.cpp
        src/core/OrganismFactory.h
        src/sim/Simulation.cpp
        src/sim/Simulation.h
        src/sim/IObserver.h
        src/sim/Observable.h
        src/util/CustomExceptions.h
        src/util/macros.h
        src/genetics.cpp
        external/instructor_files/GeneticsSimDataParser.cpp
        external/instructor_files/GeneticsSimDataParser.h
        src/sim/Scoreboard.cpp src/sim/Scoreboard.h)

add_executable(genetics ${SOURCE_FILES})

# The instructor provided test configurations in the form of .xml files.
file(COPY
        external/instructor_files/GeneticsSim2a.xml
        external/instructor_files/GeneticsSim2b.xml
     DESTINATION build/)

# End main source setup
# Begin test setup

# Download and unpack googletest at configure time
configure_file(external/CMakeLists.txt.in external/gtest/googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/external/gtest/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/external/gtest/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/external/gtest/googletest-src
        ${CMAKE_BINARY_DIR}/external/gtest/googletest-build)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()

set(TEST_FILES
        tests/main.cpp
        tests/AlleleTests.cpp tests/MasterGeneTests.cpp tests/GeneTests.cpp tests/GeneFactoryTests.cpp tests/MasterGeneIndexTests.cpp tests/ChromosomeTests.cpp tests/OrganismTests.cpp)

add_executable(tests ${TEST_FILES})
target_link_libraries(tests pthread gtest)