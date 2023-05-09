#include <iostream>
using namespace std;

int main()
{
    int n, fa;
    
    do {
        fa *= n;
        n++;
        cout << "n = " << n << endl;
    } while(n <= 10);

    cout << "fa = " << fa << endl;

    return 0;
}