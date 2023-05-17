#include <iostream>
#include "swap.hpp"

using namespace std;

int main()
{
    int a = 1, b = 2;
    cout << "Before swapping: a = " << a << ", b = " << b << endl;
    if (!swap(&a, &b))
    {
        cout << "Error!" << endl;
        return 0;
    }
    cout << "After swapping: a = " << a << ", b = " << b << endl;
}