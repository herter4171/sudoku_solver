//
// Created by Justin Herter on 11/14/20.
//

#include "get_standard.h"

std::set<int> get_standard()
{
    std::vector<int> standard;

    for (int i = 1; i < 10; i++)
    {
        standard.push_back(i);
    }

    return std::set<int>(standard.begin(), standard.end());
}