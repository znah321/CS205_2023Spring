#include <iostream>
#include "swap.hpp"

int swap(int* a, int* b)
{
    if (a == NULL || b == NULL)
    {
        std::cout << "The input cannot be null!" << std::endl;
        return 0;
    }
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return 1;
}