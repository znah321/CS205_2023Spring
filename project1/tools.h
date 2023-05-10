#pragma once
#include <stdbool.h>

#define MAX_LEN 32

bool isValid(const int argc, char** argv, char* num1, char* num2, char* operator, int* info);
void preprocess(char** argv, char* num1, char* num2, int* info);
bool isNumber(const char* str);
void add(const char num1[], const char num2[], const int* info);
void minus(const char num1[], const char num2[], const int flag, const int* info);
void multiply(const char num1[], const char num2[], const int* info);
int ctoi(const char c);
int compare(const char num1[], const char num2[]);
int getDotPos(const char* str, const int len);