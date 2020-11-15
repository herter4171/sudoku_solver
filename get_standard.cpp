//
// Created by Justin Herter on 11/14/20.
//

#include "get_standard.h"

std::vector<int> get_standard()
{
    std::vector<int> standard;

    for (int i = 1; i < 10; i++)
    {
        standard.push_back(i);
    }

    return standard;
}