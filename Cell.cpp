//
// Created by Justin Herter on 11/14/20.
//

#include "Cell.h"

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
        _choices = get_standard();
    }
}

bool Cell::is_empty()
{
    return _val == _empty_val;
}

int Cell::get_val()
{
    return _val;
};

void Cell::update_choices(std::vector<int> &sub_choices)
{
    std::set<int> new_choices;

    std::set_union(
            sub_choices.begin(), sub_choices.end(),
            _choices.begin(), _choices.end(),
            std::inserter(new_choices, new_choices.begin()));

    _choices = new_choices;
}

int Cell::get_choice_count()
{
    return _choices.size();
}

void Cell::set_single_val()
{
    if (_choices.size() == 1)
    {
        auto iter = _choices.begin();
        _val = *iter;
    }
}