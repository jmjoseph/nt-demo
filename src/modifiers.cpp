#include "modifiers.h"

#include <iostream>
#include <vector>

std::vector<int> get_multiples(const std::vector<int> &t,
                               int threshold)
{
    std::vector<int> multiples;

    for (int i: t)
    {
        // 0 is technically a multiple of any number...
        // but I'll exclude it since it doesn't contribute to the sum.
        if (i > 0 && i % threshold == 0)
        {
            multiples.push_back(i);
        }
    }

    return multiples;
}
