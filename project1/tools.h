#pragma once
#include <stdbool.h>

#define MAX_LEN 32

bool isValid(const int argc, char** argv, char* num1, char* num2, char* operator, int* info);
void preprocess(char** argv, char* num1, char* num2, int* info);
char* postprocess(char* num, const int len);
bool isNumber(const char* str);
char* add(const char* num1, const char* num2, const int* info);
char* minus(const char* num1, const char* num2, const int flag, const int* info);
char* multiply(const char* num1, const char* num2, const int* info);
void divide(const char* num1, const char* num2, const int* info);
int ctoi(const char c);
int compare(const char num1[], const char num2[]);
int getDotPos(const char* str, const int len);