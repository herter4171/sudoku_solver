//
// Created by Justin Herter on 11/14/20.
//

#include "CellGroup.h"

CellGroup::CellGroup(CellVec cells)
{
    _cells = cells;
    _standard = get_standard();
}

bool CellGroup::is_solved()
{
    return _vals == _standard;
}

void CellGroup::update_options()
{
    _update_used_vals();

    int unused_size = _standard.size() - _vals.size();
    std::vector<int> unused(unused_size);

    std::sort(_vals.begin(), _vals.end());

    auto it = std::set_difference(
            _standard.begin(), _standard.end(),
            _vals.begin(), _vals.end(),
            unused.begin());

    unused.resize(it - unused.begin());

    for (auto &p_cell: _cells)
    {
        if (p_cell->is_empty())
            p_cell->update_choices(unused, _vals);
    }
}

void CellGroup::_update_used_vals()
{
    _vals.clear();

    for (auto &p_cell : _cells)
    {
        if (!p_cell->is_empty())
            _vals.push_back(p_cell->get_val());
    }
}