#include <iostream>

using namespace std;

int main()
{
    float a = 0.1f;
    float b = 0.2f;
    float c = 0.3f;

    printf("Formatting output with printf:\n");
    printf("%.2f\n", a);
    printf("%.2f\n", b);
    printf("%.2f\n", c);

    cout.flags(ios::fixed);
    cout.precision(2);
    cout << "Formatting output with cout:" << endl;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    return 0;
}