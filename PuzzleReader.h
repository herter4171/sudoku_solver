//
// Created by Justin Herter on 11/14/20.
//

#ifndef SUDOKU_SOLVER_PUZZLEREADER_H
#define SUDOKU_SOLVER_PUZZLEREADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

class PuzzleReader {
public:
    typedef std::vector<std::vector<std::string>> BasicGrid;

    PuzzleReader(std::string inp_path);

    BasicGrid get_grid();

    // Always reading a 9x9 grid
    static const int side_length = 9;

private:
    // Store lines for subsequent parse
    std::string _lines[side_length];
};


#endif //SUDOKU_SOLVER_PUZZLEREADER_H
