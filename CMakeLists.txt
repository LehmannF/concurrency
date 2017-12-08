cmake_minimum_required(VERSION 2.6)
project(crowd_movement)

#define platform independent variables
SET(GCC_COMPILE_FLAGS "-g -ansi -Wall -fpermissive -Wextra -Wold-style-cast -Woverloaded-virtual -D_DEBUG_ -std=c++11")
add_definitions(${GCC_COMPILE_FLAGS}) 

# dossier de build
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "build")

# dossier contenant les sources
set(SOURCESV1 "sources/v1")
set(SOURCESV2 "sources/v2")

# dossier contenant les tests
set(TESTV1S "tests/v1")


# Ajout de google test pour les tests unitaires
ADD_SUBDIRECTORY(gtest-1.8.0)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Test de terrain
add_executable(TerrainTests ${TESTV1S}/TerrainTests.cpp ${SOURCESV1}/Obstacle.cpp ${SOURCESV1}/Terrain.cpp ${SOURCESV1}/Tile.cpp)
target_link_libraries(TerrainTests gtest gtest_main)
add_test(${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/TerrainTests ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/TerrainTests)

# Test de Personne
add_executable(PersonneTests ${TESTV1S}/PersonneTests.cpp ${SOURCESV1}/Personne.cpp ${SOURCESV1}/Terrain.cpp ${SOURCESV1}/Tile.cpp ${SOURCESV1}/Obstacle.cpp)
target_link_libraries(PersonneTests gtest gtest_main)
add_test(${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/PersonneTests ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/PersonneTests)

# Main executable
add_executable(main ${SOURCESV1}/Personne.cpp ${SOURCESV1}/main.cpp ${SOURCESV1}/Obstacle.cpp ${SOURCESV1}/Terrain.cpp ${SOURCESV1}/Tile.cpp)
target_link_libraries(main pthread)

# Main executable
add_executable(main2 ${SOURCESV2}/main.cpp ${SOURCESV2}/Obstacle.cpp ${SOURCESV2}/Terrain.cpp ${SOURCESV2}/Tile.cpp ${SOURCESV2}/SliceTerrain.cpp)
target_link_libraries(main2 pthread)
