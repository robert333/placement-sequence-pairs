cmake_minimum_required(VERSION 3.7)
project(Placement)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Werror")

set(SOURCE_FILES
        source/main.cpp
        source/Vector2.cpp
        source/Vector2.hpp
        source/Instance.cpp
        source/Instance.hpp
        source/Placement.cpp
        source/Placement.hpp
        source/SequencePair.cpp
        source/SequencePair.hpp
        source/Graph.cpp
        source/Graph.hpp
        source/Algorithm.cpp
        source/Algorithm.hpp
        source/TopologicalOrder.cpp
        source/TopologicalOrder.hpp
        source/IterativeBooleanAssignment.cpp
        source/IterativeBooleanAssignment.hpp
        )

add_executable(Placement ${SOURCE_FILES})