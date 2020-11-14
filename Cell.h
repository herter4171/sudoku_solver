//
// Created by Justin Herter on 11/14/20.
//

#ifndef SUDOKU_SOLVER_CELL_H
#define SUDOKU_SOLVER_CELL_H

#include <string>
#include <stdexcept>
#include <set>
#include <algorithm>
#include <memory>
#include <vector>

#include "get_standard.h"

class Cell {
public:
    Cell(int row, int col, std::string init_val);

    bool is_empty();

    int get_val();

    void update_choices(std::vector<int> &sub_choices);

    int get_choice_count();

    void set_single_val();

private:
    // Grid indices
    int _row, _col;

    // Empty cells have zero as _val
    const int _empty_val = 0;

    // Cell value (Zero for blank)
    int _val;

    std::set<int> _choices;
};


#endif //SUDOKU_SOLVER_CELL_H
