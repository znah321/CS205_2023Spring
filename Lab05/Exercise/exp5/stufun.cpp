#include <iostream>
#include "stuinfo.hpp"
using namespace std;

void inputstu(stuinfo stu[] , int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "------------------------------" << endl;
        cout << "Input name of student " << i + 1 << ": ";
        cin >> stu[i].name;
        cout << "Input scores of student " << i + 1 << ": ";
        cin >> stu[i].score[0] >> stu[i].score[1] >> stu[i].score[2];
        stu[i].ave = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2]) / 3;
    }
}
void showstu(stuinfo stu[] , int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "--------------- Student " << i + 1 << " ---------------" << endl;
        cout << "Name: " << stu[i].name;
        cout << "Score: " << stu[i].score[0] << ", " << stu[i].score[1] << ", " << stu[i].score[2] << endl;
        cout << "Average: " << stu[i].ave << endl;
    }
}