#include <iostream>
using namespace std;

struct stuinfo
{
    string name;
    int age;
};

template <typename T>
int compare(const T& a, const T& b)
{
    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    else
        return 0;
}

template<>
int compare(const stuinfo& a, const stuinfo& b)
{
    if (a.age > b.age)
        return 1;
    else if (a.age < b.age)
        return -1;
    else
        return 0;
}

template int compare(const int&, const int&);
template int compare(const float&, const float&);
template int compare(const char&, const char&);
template int compare(const stuinfo&, const stuinfo&);

int main()
{
    int a1 = 1, b1 = 2;
    float a2 = 1.2f, b2 = 0.3f;
    char a3 = 'g', b3 = 'c';
    stuinfo a4 {"zhangsan", 18};
    stuinfo b4 {"lisi", 24};

    cout << "Compare of the two integers: " << compare(a1, b1) << endl;
    cout << "Compare of the two floats: " << compare(a2, b2) << endl;
    cout << "Compare of the two characters: " << compare(a3, b3) << endl;
    cout << "Compare of the two structers: " << compare(a4, b4) << endl;
    return 0;
}