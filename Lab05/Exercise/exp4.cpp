#include <iostream>
using namespace std;

int main()
{
    int *p = new int[5];

    for(int i = 0; i < 5; i++)
        p[i] = i;
    
    int *q = (int*)(p + 5);
    for(int i = 1; i <= 5; i++)
        cout << *(q - i) << endl;
    return 0;
}