#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "tools.h"

bool isValid(const int argc, char** argv, char* num1, char* num2, char* operator, int* info)
{
    // check the number of inputs
    if (argc != 4)
    {
        printf("Please check the number of input!\n");
        return false;
    }

    // check the operator
    if (argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != 'x' && argv[2][0] != '/')
    {
        printf("Wrong operator!\n");
        return false;
    }
    *operator = argv[2][0];

    // check if the input are numbers
    int len1 = strlen(argv[1]);
    int len2 = strlen(argv[3]);
    char t_num1[MAX_LEN];
    char t_num2[MAX_LEN];
    strncpy(t_num1, argv[1], strlen(argv[1]));
    strncpy(t_num2, argv[3], strlen(argv[3]));
    preprocess(argv, num1, num2, info);
    if (!isNumber(num1) || !isNumber(num2))
    {
        printf("The inputs are not numbers!\n");
        return false;
    }

    // when the operator is "/", check if num2 equals to zero
    char* ptr = NULL;
    if (fabs(strtod(argv[3], &ptr)) < __DBL_EPSILON__)
    {
        printf("A number cannot be divied by zero!\n");
        return false;
    }

    // print to the screen
    for(int i = 0; i < len1; i++)
        printf("%c", t_num1[i]);
    printf(" %c ", *operator);
    for(int i = 0; i < len2; i++)
        printf("%c", t_num2[i]);
    printf(" = ");

    return true;
}

void preprocess(char** argv, char* num1, char* num2, int* info)
{
    int i, j, k, l;
    int len1 = strlen(argv[1]);
    int dotPos1 = getDotPos(argv[1], len1);
    int len2 = strlen(argv[3]);
    int dotPos2 = getDotPos(argv[3], len2);

    // remove "." from the string
    for(i = 0, j = 0; i < len1; i++)
    {
        if (argv[1][i] == '.')
            continue;
        num1[j++] = argv[1][i];
    }
    num1[j] = '\0';
    for(k = 0, l = 0; k < len2; k++)
    {
        if (argv[3][k] == '.')
            continue;
        num2[l++] = argv[3][k];
    }
    num2[l] = '\0';
    info[0] = dotPos1;
    info[1] = dotPos2;

    // align behind the dot
    if (dotPos1 > dotPos2)
    {
        int m;
        for(m = 0; m < dotPos1 - dotPos2; m++)
            num2[l + m] = '0';
        num2[l + m] = '\0';
    }
    else
    {
        int m;
        for(m = 0; m < dotPos2 - dotPos1; m++)
            num1[j + m] = '0';
        num1[j + m] = '\0';
    }
}

char* postprocess(char* num, const int len)
{
    int i;
    for(i = len - 1; i >= 0; i--)
    {
        if (num[i - 1] != '0')
            break;
    }
    if (num[i - 1] == '.') // when the numult is an integer
        num[i - 1] = '\0';
    else
        num[i] = '\0';

    return num;
}

bool isNumber(const char* str)
{
    int len = strlen(str);
    for(int i = 0; i < len; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

char* add(const char* num1, const char* num2, const int* info)
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len = len1 > len2 ? len1 : len2;
    char _res[len + 1];
    memset(&_res, 0, (len+1)*sizeof(char));

    for(int i = 0; i < len + 1; i++)
    {
        _res[len - i] += ctoi(num1[len1 - i - 1]) + ctoi(num2[len2 - i - 1]);
        _res[len - i - 1] += _res[len - i] / 10;
        _res[len - i] %= 10;
    }

    // Postprocess
    int cnt = 0;
    while (_res[cnt] == 0) {cnt++;} // delete 0 at the start

    int _len;
    if (info[0] > 0 || info[1] > 0)
        _len = len - cnt + 2;
    else
        _len = len - cnt + 1;
    char* res = (char*)malloc(_len * sizeof(char));
    memset(res, 0, _len * sizeof(char));

    int pos = info[0] > info[1] ? info[0] : info[1];
    for(int i = cnt, j = 0; i < len + 1; i++)
    {
        if (i == len + 1 - pos && pos)
            res[j++] = '.';
        res[j++] = _res[i] + '0';
    }
    res[_len] = '\0';

    // delete 0 at the end (only when the input are float numbers and res[len-1] == '0')
    len = strlen(res);
    if (pos && res[len-1] == '0')
        res = postprocess(res, len);

    return res;
}

char* minus(const char* num1, const char* num2, const int flag, const int* info)
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len = len1 > len2 ? len1 : len2;
    char _res[len];
    memset(&_res, 0, (len)*sizeof(char));

    for(int i = 0; i < len + 1; i++)
    {
        if (num1[len1 - i - 1] < num2[len2 - i - 1])
        {
            _res[len - i - 1] += 10 + ctoi(num1[len1 - i - 1]) - ctoi(num2[len2 - i - 1]);
            _res[len - i - 2] -= 1;
        }
        else
        {
            _res[len - i - 1] += ctoi(num1[len1 - i - 1]) - ctoi(num2[len2 - i - 1]);
        }
    }

    // Postprocess
    if (info[0] > 0 || info[1] > 0)
        len += 1;
    char* res = (char*)malloc(len * sizeof(char));
    memset(res, 0, len * sizeof(char));

    int pos = info[0] > info[1] ? info[0] : info[1];
    for(int i = 0, j = 0; i < len; i++)
    {
        if (i == len - pos - 1 && pos)
            res[j++] = '.';
        res[j++] = _res[i] + '0';
    }
    res[len] = '\0';

    // delete 0 at the end (only when the input are float numbers and res[len-1] == '0')
    len = strlen(res);
    if (pos && res[len-1] == '0')
        res = postprocess(res, len);

    return res;
}

char* multiply(const char* num1, const char* num2, const int* info)
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len = len1 + len2 + 1;
    char _res[len];
    memset(&_res, 0, (len)*sizeof(char));

    for(int i = 0; i < len1; i++)
    {
        for(int j = 0; j < len2; j++)
        {
            _res[len - 1 - i - j] += ctoi(num1[len1 - i - 1]) * ctoi(num2[len2 - j - 1]);
            _res[len - 2 - i - j] += _res[len - 1 - i - j] / 10;
            _res[len - 1 - i - j] %= 10;
        }
    }

    // Postprocess
    int cnt = 0;
    while (_res[cnt] == 0) {cnt++;} // delete zero at the start

    if (info[0] > 0 || info[1] > 0)
        len += 1;
    char* res = (char*)malloc(len * sizeof(char));
    memset(res, 0, len * sizeof(char));

    // insert "."
    int pos = info[0] + info[1];
    int offset = abs(info[0] - info[1]);
    for(int i = cnt, j = 0; i < len1 + len2 + 1; i++)
    {
        if (i == len1 + len2 + 1 - offset - pos)
            res[j++] = '.';
        res[j++] = _res[i] + '0';
    }
    res[len] = '\0';

    // delete zero at the end (only when the input are float numbers)
    if (pos)
        res = postprocess(res, len);

    return res;
}

void divide(const char* num1, const char* num2, const int* info)
{

}

// transform character into integer
int ctoi(const char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    else
        return 0;
}

// compare two strings
int compare(const char num1[], const char num2[])
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    if (len1 > len2)
    {
        return 1;
    }
    else if (len1 < len2)
    {
        return -1;
    }
    else
    {
        for(int i = 0; i < len1; i++)
        {
            if (num1[i] > num2[i])
                return 1;
            else if (num1[i] < num2[i])
                return -1;
            else
                return 0;
        }
    }
}

// get the index of "." in the string
int getDotPos(const char* str, const int len)
{
    for(int i = len - 1; i >= 0; i--) {
        if (str[i] == '.')
            return len - 1 - i;
    }
    return 0;
}