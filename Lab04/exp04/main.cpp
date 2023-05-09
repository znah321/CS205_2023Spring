#include <iostream>
#include "fib.hpp"

using namespace std;

int main()
{
    int n;
    int result = -1;
    while (result == -1)
    {
        cout << "Please input a positive number: ";
        cin >> n;
        if (n > 0)
        {   
            for(int i = 1; i <= n; i++)
                cout << fibonacci(i) << " ";
            break;
        }
    }
    cout << endl;
    return 0;
}