cmake_minimum_required(VERSION 3.12)
project(pathfinding)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic)

add_library(pathfinding_core src/Maze.cpp src/MazeGenerator.cpp src/DebugGenerator.cpp) 
target_include_directories(pathfinding_core PUBLIC include)

# Put Your .cpp files in line below
add_executable(pathfinding src/main.cpp)
target_link_libraries(pathfinding pathfinding_core)