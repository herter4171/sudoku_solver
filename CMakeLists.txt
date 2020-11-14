# cmake_minimum_required(VERSION <specify CMake version here>)
project(sudoku_solver)
cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 17)

find_package(Boost)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(sudoku_solver main.cpp PuzzleReader.cpp PuzzleReader.h SudokuGrid.cpp SudokuGrid.h Cell.cpp Cell.h)