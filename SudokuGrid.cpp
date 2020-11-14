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

SudokuGrid::CellVec SudokuGrid::_get_row(int row_ind)
{
    int begin_ind = row_ind*side_length;
    auto iter = _cells.begin() + begin_ind;

    return CellVec(iter, iter + side_length);
}

SudokuGrid::CellVec SudokuGrid::_get_col(int col_ind)
{
    CellVec col;

    for (int i = col_ind; i < side_length*side_length; i += side_length)
    {
        col.push_back(_cells[i]);
    }

    return col;
}

SudokuGrid::CellVec SudokuGrid::_get_square(int square_ind)
{
    int start_row = 0;
    int sub_length = sqrt(side_length);

    // Establish start row if not zero
    if (square_ind >= sub_length)
    {
        start_row = 3;

        if (square_ind >= sub_length*2)
        {
            start_row *= 2;
        }
    }

    int start_col;

    for (int i = 0; i < sub_length; i++)
    {
        if ((square_ind - i) % sub_length == 0)
        {
            start_col = sub_length*i;
        }
    }

    CellVec square_cells;

    int start_ind = start_row*side_length + start_col;

    for (int i = 0; i < sub_length; i++)
    {
        int curr_ind = start_ind + i*side_length;
        auto begin = _cells.begin() + curr_ind;
        auto end = begin + sub_length;

        square_cells.insert(square_cells.end(), begin, end);
    }

    return square_cells;
}