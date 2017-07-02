cmake_minimum_required(VERSION 3.7)
project(src)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        src/building_blocks/gene/Gene.cpp
        src/building_blocks/gene/Gene.h
        src/building_blocks/gene/GeneFactory.cpp
        src/building_blocks/gene/GeneFactory.h
        src/building_blocks/gene/MasterGene.cpp
        src/building_blocks/gene/MasterGene.h
        src/building_blocks/gene/MasterGeneFactory.cpp
        src/building_blocks/gene/MasterGeneFactory.h
        src/building_blocks/gene/MasterGeneIndex.cpp
        src/building_blocks/gene/MasterGeneIndex.h
        src/building_blocks/Allele.cpp
        src/building_blocks/Allele.h
        src/building_blocks/Chromosome.cpp
        src/building_blocks/Chromosome.h
        src/building_blocks/ChromosomeFactory.cpp
        src/building_blocks/ChromosomeFactory.h
        src/building_blocks/Organism.cpp
        src/building_blocks/Organism.h
        src/building_blocks/OrganismFactory.cpp
        src/building_blocks/OrganismFactory.h
        src/core/Simulation.cpp
        src/core/Simulation.h
        src/io/GeneticsSimDataParser.cpp
        src/io/GeneticsSimDataParser.h
        src/sync/IObserver.h
        src/sync/Observable.h
        src/utils/CustomExceptions.h
        src/utils/macros.h
        src/genetics.cpp
        # Probably not needed - instructor_files/GeneticsSimDataParser.cpp
        # Probably not needed - instructor_files/GeneticsSimDataParser.h
        # Probably not needed - ColemanXMLParser.cpp
        # Probably not needed - ColemanXMLParser.h
        )

add_executable(genetics ${SOURCE_FILES})

# The instructor provided test configurations in the form of .xml files.
file(COPY
        external/instructor_files/GeneticsSim2a.xml
        external/instructor_files/GeneticsSim2b.xml
     DESTINATION build/)

# End main source setup
# Begin test setup

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in external/gtest/googletest-download/CMakeLists.txt)
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
        tests/utils.h tests/AlleleTests.cpp tests/MasterGeneTests.cpp)

add_executable(tests ${TEST_FILES})
target_link_libraries(tests pthread gtest)