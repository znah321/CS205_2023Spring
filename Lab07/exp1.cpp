#include <iostream>
#include <string.h>
using namespace std;

const char* match(const char* s, char ch)
{
    int len = strlen(s);
    int start = -1;
    for(int i = 0; i < len; i++)
    {
        if (s[i] == ch)
        {
            start = i;
            break;
        }
    }

    if (start == -1)
    {
        cout << "Not found" << endl;
        return NULL;
    }
    else
    {
        char* res = (char*)malloc((len - start) * sizeof(char));
        for(int i = start; i < len; i++)
            res[i - start] = s[i];
        return res;
    }
}

int main()
{
    char s[30];
    char ch;
    cout << "Please input a string: " << endl;
    cin.getline(s, 30);
    cout << "Please input a character: " << endl;
    cin >> ch;
    
    const char * r = match(s, ch);
    if (r)
        printf("%s\n", r);
    return 0;
}