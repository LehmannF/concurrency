cmake_minimum_required(VERSION 2.6)
project(crowd_movement)

#define platform independent variables
SET(GCC_COMPILE_FLAGS "-g -ansi -Wall -Wextra -Wold-style-cast -Woverloaded-virtual -D_DEBUG_ -std=c++11")
add_definitions(${GCC_COMPILE_FLAGS}) 

# dossier de build
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "build")

# dossier contenant les sources
set(SOURCES "sources")

# dossier contenant les tests
set(TESTS "tests")

# Ajout de google test pour les tests unitaires
ADD_SUBDIRECTORY(gtest-1.8.0)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Tests ${TESTS}/TerrainTests.cpp ${SOURCES}/Terrain.cpp)
target_link_libraries(Tests gtest gtest_main)
add_test(${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Tests ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Tests)
