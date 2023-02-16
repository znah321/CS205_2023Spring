#include <iostream>
#include "tools.hpp"

using namespace std;

int main(int argc, char** argv)
{
    // 检查命令行参数
    if (argc != 1)
    {
        // 检查输入参数的个数
        if (argc < 3)
        {
            cout << "The number of input is not enough!" << endl;
            return 0;
        }
        else if (argc > 3)
        {
            cout << "The number of input is too much!" << endl;
            return 0;
        }
        else
        {
            int typeA = checkInputType(argv[1]);
            int typeB = checkInputType(argv[2]);
            // 判断输入的是否为两个整数
            if (!typeA || !typeB)
            {
                cout << "The input cannot be interpreted as numbers!" << endl;
                return 0;
            }
            multiplication(argv[1], typeA, argv[2], typeB);
        }
    }
    else
    {
        char num1[100], num2[100];
        cout << "Please input two numbers: " << endl;
        cin >> num1 >> num2;

        char next;
        while ((next = getchar()) != '\n')
        {
            if (next != ' ')
            {
                while (getchar() != '\n');
                cout << "Wrong number of input, please input two integers: " << endl;
                cin >> num1 >> num2;
            }
        }
        
        int typeA = checkInputType(num1);
        int typeB = checkInputType(num2);
        if (!typeA || !typeB)
        {
            cout << "The input cannot be interpreted as numbers!" << endl;
            return 0;
        }
        multiplication(num1, typeA, num2, typeB);
    }
}
