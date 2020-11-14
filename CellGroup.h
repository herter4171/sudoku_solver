//
// Created by Justin Herter on 11/14/20.
//

#ifndef SUDOKU_SOLVER_CELLGROUP_H
#define SUDOKU_SOLVER_CELLGROUP_H

#include <memory>
#include <vector>
#include <set>
#include <algorithm>

#include "get_standard.h"
#include "Cell.h"

class CellGroup {
public:
    typedef std::vector<std::shared_ptr<Cell>> CellVec;

    CellGroup(CellVec cells);

    bool is_solved();

    void update_options();

private:

    void _update_used_vals();



    CellVec _cells;

    std::set<int> _vals, _standard;
};


#endif //SUDOKU_SOLVER_CELLGROUP_H
