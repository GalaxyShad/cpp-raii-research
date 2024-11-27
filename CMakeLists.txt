cmake_minimum_required(VERSION 3.28)
project(cpp_raii_research)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_raii_research main.cpp
        SquareMatrix.cpp)
