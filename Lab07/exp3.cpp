#include <iostream>
#include <math.h>
using namespace std;

bool vabs(int* p, int n);
bool vabs(float* p, int n);
bool vabs(double* p, int n);

int main()
{
    int* p1 = new int[5]{1, 2, -3, -4, 5};
    float* p2 = new float[5]{111.f, 222.f, 333.f, -444.f, -555.f};
    double* p3 = new double[5]{-11., -22, -33., 44., 55.};
    if (vabs(p1, 5))
    {
        for(int i = 0; i < 5; i++)
            cout << p1[i] << " ";
        cout << endl;
    }
    if (vabs(p2, 5))
    {
        for(int i = 0; i < 5; i++)
            cout << p2[i] << " ";
        cout << endl;
    }
    if (vabs(p3, 5))
    {
        for(int i = 0; i < 5; i++)
            cout << p3[i] << " ";
        cout << endl;
    }
}

bool vabs(int* p, int n)
{
    if (!p)
        return false;
    for(int i = 0; i < n; i++)
        p[i] = p[i] > 0 ? p[i] : -p[i];
    return true;
}

bool vabs(float* p, int n)
{
    if (!p)
        return false;
    for(int i = 0; i < n; i++)
    {
        p[i] = p[i] > 0 ? p[i] : -p[i];
    }
    return true;
}

bool vabs(double* p, int n)
{
    if (!p)
        return false;
    for(int i = 0; i < n; i++)
    {
        p[i] = p[i] > 0 ? p[i] : -p[i];
    }
    return true;
}