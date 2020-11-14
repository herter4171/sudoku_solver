//
// Created by Justin Herter on 11/14/20.
//

#include "SudokuGrid.h"

SudokuGrid::SudokuGrid(PuzzleReader::BasicGrid basic_grid)
{
    int row_ind = 0;

    for (auto &row_vals : basic_grid)
    {
        for (int col_ind = 0; col_ind < side_length; col_ind++)
        {
            Cell* new_cell_raw = new Cell(row_ind, col_ind, row_vals[col_ind]);
            std::shared_ptr<Cell> new_cell(new_cell_raw);
            _cells.push_back(new_cell);
        }
    }
}

void SudokuGrid::print_grid()
{
    int ind = 0, row = 0;
    int sub_length = sqrt(side_length);

    for (auto &p_cell : _cells)
    {
        int val = p_cell->get_val();

        if (val == 0)
        {
            std::cout << "* ";
        }
        else
        {
            std::cout << val << " ";
        }

        ind++;

        if (ind % sub_length == 0)
        {
            std::cout << " | ";
        }

        if (ind % side_length == 0)
        {
            row += 1;
            std::cout << std::endl;

            if (row % sub_length == 0)
            {
                std::cout << "--------------------------" << std::endl;
            }
        }
    }
}