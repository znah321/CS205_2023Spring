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

    char* res;
    switch (operator)
    {
        case '+':
        {
            res = add(num1, num2, &info);
            break;
        }
        case '-':
        {
            int flag = compare(num1, num2);
            if (flag > 0)
                res = minus(num1, num2, flag, &info);
            else
            {
                res = minus(num2, num1, flag, &info);
                res = res - 1;
                res[0] = '-';
            }
            break;
        }
        case 'x':
        {
            res = multiply(num1, num2, &info);
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
    if (res != NULL)
        printf("%s", res);
    printf("\n");
}