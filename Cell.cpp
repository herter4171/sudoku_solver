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
        _max_choice_count = _choices.size();
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

void Cell::update_choices(std::vector<int> &sub_choices, std::vector<int> group_forbidden)
{
    std::vector<int> group_choices(_max_choice_count),
                     new_choices(_max_choice_count),
                     new_forbidden(_max_choice_count);

    // Get unfiltered choices from the calling cell group
    auto it = std::set_intersection(
            sub_choices.begin(), sub_choices.end(),
            _choices.begin(), _choices.end(),
            group_choices.begin());

    group_choices.resize(it - group_choices.begin());

    // Update forbidden vals from the calling cell group
    it = std::set_union(group_forbidden.begin(), group_forbidden.end(),
                        _forbidden.begin(), _forbidden.end(),
                        new_forbidden.begin());

    new_forbidden.resize(it - new_forbidden.begin());
    _forbidden = new_forbidden;

    // Remove forbidden vals from calling cell group's choices
    it = std::set_difference(group_choices.begin(), group_choices.end(),
                             _forbidden.begin(), _forbidden.end(),
                             new_choices.begin());

    new_choices.resize(it - new_choices.begin());
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

        _choices.clear();
        is_new = true;
    }
}

void Cell::set_square_cells(Cell::CellVec square_cells)
{
    for (auto &curr_cell : square_cells)
    {
        if (!is_me(curr_cell))
        {
            _square_cells.push_back(curr_cell);
        }
    }
}

void Cell::check_neighbors()
{
    std::vector<int> shared_forbidden;

    for (auto &curr_cell : _square_cells)
    {
        if (curr_cell->_val != _empty_val)
        {
            continue;
        }

        if (shared_forbidden.size() == 0)
        {
            shared_forbidden = curr_cell->_forbidden;
        }
        else if (curr_cell->_forbidden.size() > 0)
        {
            std::vector<int> new_forbidden(_max_choice_count);

            auto it = std::set_intersection(
                    curr_cell->_forbidden.begin(),
                    curr_cell->_forbidden.end(),
                    shared_forbidden.begin(),
                    shared_forbidden.end(),
                    new_forbidden.begin());

            new_forbidden.resize(it - new_forbidden.begin());
            shared_forbidden = new_forbidden;
        }
    }

    if (shared_forbidden.size() > 0)
    {
        std::vector<int> narrowed_choices(_max_choice_count);

        auto it = std::set_intersection(
                _choices.begin(),
                _choices.end(),
                shared_forbidden.begin(),
                shared_forbidden.end(),
                narrowed_choices.begin());

        narrowed_choices.resize(it - narrowed_choices.begin());

        if (narrowed_choices.size() > 0)
        {
            _choices = narrowed_choices;
        }
    }
}

bool Cell::is_me(std::shared_ptr<Cell> other)
{
    return other->_row == _row && other->_col == _col;
}
