#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"

int main(int argc, char** argv)
{
    char num1[MAX_LEN];
    char num2[MAX_LEN];
    char operator;
    char* ptr = &operator;
    int info[2];

    // check validity
    if (!isValid(argc, argv, &num1, &num2, ptr, &info))
        return 0;

    switch (operator)
    {
        case '+':
        {
            add(num1, num2, &info);
            break;
        }
        case '-':
        {
            int flag = compare(num1, num2);
            if (flag > 0)
                minus(num1, num2, flag, &info);
            else
                minus(num2, num1, flag, &info);
            break;
        }
        case 'x':
        {
            multiply(num1, num2, &info);
            break;
        }
        case '/':
        {
            divide(argv[1], argv[3]);
            break;
        }
        default:
            break;
    }
    printf("\n");
}