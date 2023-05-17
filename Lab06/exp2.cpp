#include <iostream>
using namespace std;

int* create_array (int size)
{
    if (size <= 0)
    {
        printf("The size of array should be positive!\n");
        return NULL;
    }
    int *arr = (int*)malloc(size*sizeof(int));
    for(int i = 0; i < size; i++)
        arr[i] = i * 10;
    return arr;
}

int main()
{
    int len = 16;
    int *ptr = create_array(len);
    for(int i = 0; i < len; i++)
        cout << ptr[i] << " ";
    printf("\n");
    free(ptr);
    return 0;
}

