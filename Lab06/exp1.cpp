#include <iostream>
using namespace std;
#define SIZE 5

int sum(const int *pArray, int n);

int main()
{
    const int *pa = new int[SIZE]{3, 5, 8, 2, 6};
    int total = sum(pa, SIZE);
    cout << "sum = " << total << endl;
    return 0;
}

int sum(const int *pArray, int n)
{
    if (pArray == NULL)
    {
        printf("Null array!\n");
        return 0;
    }
    int s = 0;
    for(int i = 0; i < n; i++)
        s += pArray[i];
    return s;
}