//
// Created by Justin Herter on 11/14/20.
//

#include "PuzzleReader.h"

PuzzleReader::PuzzleReader(std::string inp_path)
{
    std::ifstream inp_file(inp_path.c_str());

    if (inp_file.is_open())
    {

        for (int i = 0; i < side_length; i++)
        {
            getline(inp_file, _lines[i]);
        }

        inp_file.close();
    }
}

PuzzleReader::BasicGrid PuzzleReader::get_grid()
{
    using namespace boost::algorithm;
    BasicGrid grid;

    for (int i =0 ; i < side_length; i++)
    {
        std::string row = _lines[i];
        std::vector<std::string> row_vals;

        split(row_vals, row, is_any_of(","));

        for (int j = 0; j < row_vals.size(); j++)
        {
            std::cout << row_vals[j] << std::endl;
        }

        grid.push_back(row_vals);
    }

    return grid;
}