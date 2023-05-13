#include <iostream>
#include "stuinfo.hpp"



int main()
{
    stuinfo info[3];
    int n = 3;
    
    inputstu(info, n);
    std::cout << std::endl;
    showstu(info, n);
    return 0;
}