#include <bits/stdc++.h>
using namespace std;

#ifndef BIRTHDAY_H
#define BIRTHDAY_H

class Birthday
{
private:
    int day, month, year;
    bool valid(Birthday day)
    {
        if (day.month < 1 || day.month > 12)
            return false;
        if (day.day < 1 || day.day > 31)
            return false;
        if (day.month == 2)
        {
            if (day.year % 400 == 0 || (day.year % 4 == 0 && day.year % 100 != 0))
                return day.day <= 29;
            return day.day <= 28;
        }
        if (day.month == 4 || day.month == 6 || day.month == 9 || day.month == 11)
            return day.day <= 30;
        return true;
    }

public:
    Birthday()
    {
        day = month = year = 1;
    }

    friend istream &operator>>(istream &is, Birthday &bd)
    {
        is >> bd.day >> bd.month >> bd.year;
        if (!bd.valid(bd))
            throw invalid_argument("Invalid date");
        return is;
    }

    friend ostream &operator<<(ostream &os, Birthday bd)
    {
        cout << bd.day << "/" << bd.month << "/" << bd.year;
        return os;
    }
};

#endif