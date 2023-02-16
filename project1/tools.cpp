#include <iostream>
#include <regex>
#include <string>
#include "tools.hpp"

using namespace std;

int checkInputType(char* input)
/*
    0: 不是数字
    1: 整型
    2: 浮点数
*/
{
    regex floatPattern("((\\+?|-)\\d+)(\\.\\d+)?");
    regex integerPattern("(\\+?|-)\\d+");
    bool b1 = regex_match(input, integerPattern);
    bool b2 = regex_match(input, floatPattern);
    if (!b1 && !b2) 
        return 0;
    else
        return b1 ? 1 : 2;
}

int getDotPos(char* str, int type) // 提取小数点位置
{
    if (type == 2)
    {
        for(int i = strlen(str) - 1, j = 0; i >= 0; i--, j++)
        {
            if (str[i] == '.')
                return j;
        }
    }
    return 0;
}

void multiplication(char *a, int typeA, char *b, int typeB)
{ 
    char num1[100] = {0};
    char num2[100] = {0};

    // 处理正负号和小数点
    int k, dotPos1 = 0, dotPos2 = 0;
    int flag1 = (a[0] == '-') ? -1 : 1;
    int flag2 = (b[0] == '-') ? -1 : 1;
    int sign = flag1 * flag2;
    for(int i = 0, k = 0; a[i] != '\0'; i++)
    {
        if (a[i] >= '0' && a[i] <= '9')
            num1[k++] = a[i];
    }
    for(int i = 0, k = 0; b[i] != '\0'; i++)
    {
        if (b[i] >= '0' && b[i] <= '9')
            num2[k++] = b[i];
    }

    // 提取小数点位置
    dotPos1 = getDotPos(a, typeA);
    dotPos2 = getDotPos(b, typeB);

    int length1 = strlen(num1);
    int length2 = strlen(num2);
    int dotPos = 0 + dotPos1 + dotPos2;
    char *res = (char *)malloc(sizeof(char)*(length1 + length2));  
    memset(res, 0, sizeof(char)*(length1 + length2));  

    for(int i = length1 - 1; i >= 0; i--)
    {
        for(int j = length2 - 1; j >= 0; j--)
        {
            res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0'); // 对应位乘完再累加
            res[i + j] += res[i + j + 1] / 10; // 向前一位进位
            res[i + j + 1] %= 10;
        }
    }

    int retLen = length1 + length2;
    retLen += dotPos ? 1 : 0;
    char* ret = (char *)malloc(sizeof(char)*(retLen));  
    memset(ret, 0, sizeof(char)*(retLen));

    // 还原结果
    int cnt = 0;
    while (res[cnt] == '\0') // 去掉res左边的'0'
    {
        cnt++;
    }
    for(int i = 0, k = cnt; k < length1 + length2; i++)
    {
        
        if (sign == -1 && i == 0) // 添加负号
        {
            ret[i] = '-';
            continue;
        }   
        else if (sign == 1 && i == length1 + length2 - dotPos - 1) // 添加小数点
        {
            ret[i] = '.';
        }
        else if (sign == -1 && i == length1 + length2 - dotPos) // 添加小数点
        {
            ret[i] = '.';
        }
        else
        {
            ret[i] = res[k++] + '0';
        }
    }
    cout << a << " * " << b << " = " << ret << endl;
    free(res);
    free(ret);
}