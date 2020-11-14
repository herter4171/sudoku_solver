//
// Created by Justin Herter on 11/14/20.
//

#include "Solver.h"

Solver::Solver(std::shared_ptr<SudokuGrid> grid)
{
    _the_grid = grid;
    _set_geometry();
}

void Solver::_set_geometry()
{
    // Set each row, column, and square
    for (int i = 0; i < side_length; i++) {
        _rows.emplace_back(CellGroup(_the_grid->get_row(i)));
        _cols.emplace_back(CellGroup(_the_grid->get_col(i)));
        _squares.emplace_back(CellGroup(_the_grid->get_square(i)));
    }
}

int Solver::update()
{
    int num_changed = 0;

    for (int i = 0; i < side_length; i++)
    {
        _rows[i].update_options();
        _cols[i].update_options();
        _squares[i].update_options();
    }

    for (auto &p_cell : _the_grid->get_grid())
    {
        if (p_cell->get_choice_count() == 1)
        {
            p_cell->set_single_val();
            num_changed++;
        }
    }

    return num_changed;
}