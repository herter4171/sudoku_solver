//
// Created by Justin Herter on 11/14/20.
//

#ifndef SUDOKU_SOLVER_CELL_H
#define SUDOKU_SOLVER_CELL_H

#include <string>
#include <stdexcept>
#include <algorithm>
#include <memory>
#include <vector>

#include "get_standard.h"

class Cell {
public:
    typedef std::vector<std::shared_ptr<Cell>> CellVec;

    Cell(int row, int col, std::string init_val);

    bool is_empty();

    int get_val();

    void update_choices(std::vector<int> &sub_choices, std::vector<int> group_forbidden);

    int get_choice_count();

    void set_single_val();

    void set_square_cells(CellVec square_cells);

    void check_neighbors();

    bool is_me(std::shared_ptr<Cell> other);

    bool is_new = false;

private:
    // Grid indices
    int _row, _col;

    // Empty cells have zero as _val
    const int _empty_val = 0;

    // Cell value (Zero for blank)
    int _val, _max_choice_count;

    std::vector<int> _choices, _forbidden;

    CellVec _square_cells;


};


#endif //SUDOKU_SOLVER_CELL_H
