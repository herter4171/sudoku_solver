//
// Created by Justin Herter on 11/14/20.
//

#include "Cell.h"

bool Cell::is_empty()
{
    return _val == _empty_val;
}

int Cell::get_val()
{
    return _val;
};

Cell::Cell(int row, int col, std::string init_val)
{
    _row = row;
    _col = col;

    // Attempt to set cell value
    try
    {
        _val = std::stoi(init_val);
    }
    // Set to empty val if non-integer passed
    catch(const std::invalid_argument& ia)
    {
        _val = _empty_val;
    }
}