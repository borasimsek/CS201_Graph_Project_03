cmake_minimum_required(VERSION 3.27)
project(CS201_Graph_Project_03)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CS201_Graph_Project_03
        src/Graph.cpp
        src/Graph.h
        src/Edge.cpp
        src/EdgeList.cpp
        Main.cpp
        src/LineParser.cpp
        src/FileHandler.cpp
)
