// http://www.opensky.ca/~jdhildeb/software/sudokugen/
#include <iostream>
#include <string>


#include "PuzzleReader.h"

int main() {
    std::string inp_path = "../puzzle_dashes.csv";

    PuzzleReader puz_rd(inp_path);
    PuzzleReader::BasicGrid grid = puz_rd.get_grid();
    return 0;
}