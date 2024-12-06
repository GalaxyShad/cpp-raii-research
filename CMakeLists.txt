cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 23)

project(cpp_raii_research)
add_executable(cpp_raii_research main.cpp SquareMatrix.cpp)

project(cpp_stl_alg)
add_executable(cpp_stl_alg stl_alg_main.cpp SquareMatrix.cpp)