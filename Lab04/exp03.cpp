#include <iostream>

using namespace std;

typedef enum DAY {
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
}Day;

typedef enum WEATHER {
    Sunny,
    Rainy,
    Cloudy,
    Windy,
    Snowy
}Weather;

struct DayInfo {
    Day day;
    Weather weather;
};

bool canTravel(DayInfo dayInfo)
{
    if ((dayInfo.weather == Sunny || dayInfo.weather == Cloudy) && (dayInfo.day == Sunday || dayInfo.day == Saturday))
        return true;
    return false;
}

int main()
{
    DayInfo dayInfo;
    dayInfo.weather = Sunny;
    dayInfo.day == Monday;
    
    if (canTravel(dayInfo))
        cout << "Today is a good day to travel." << endl;
    else
        cout << "Today is not a good day to travel." << endl;
}