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

# Test de terrain
add_executable(TerrainTests ${TESTS}/TerrainTests.cpp ${SOURCES}/Terrain.cpp ${SOURCES}/Tile.cpp)
target_link_libraries(TerrainTests gtest gtest_main)
add_test(${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/TerrainTests ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/TerrainTests)

# Test de Personne
add_executable(PersonneTests ${TESTS}/PersonneTests.cpp ${SOURCES}/Personne.cpp ${SOURCES}/Terrain.cpp ${SOURCES}/Tile.cpp)
target_link_libraries(PersonneTests gtest gtest_main)
add_test(${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/PersonneTests ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/PersonneTests)