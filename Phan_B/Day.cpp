#include <iostream>
#include <exception>
using namespace std;

#ifndef DAY_H
#define DAY_H

// đây là ngày tháng năm phục vụ cho việc thêm vào cây nhị phân tìm kiếm
class Day
{
private:
    int d, m, y; // ngày tháng năm
    bool valid(Day day)
    {
        if (day.m < 1 || day.m > 12)
            return false;
        if (day.d < 1 || day.d > 31)
            return false;
        if (day.m == 2)
        {
            if (day.y % 400 == 0 || (day.y % 4 == 0 && day.y % 100 != 0))
                return day.d <= 29;
            return day.d <= 28;
        }
        if (day.m == 4 || day.m == 6 || day.m == 9 || day.m == 11)
            return day.d <= 30;
        return true;
    }

public:
    Day(int d = 1, int m = 1, int y = 1)
    {
        this->d = d;
        this->m = m;
        this->y = y;
        if (!valid(*this))
            throw invalid_argument("Invalid date");
    }

    // các toán tử nhập xuất
    friend istream &operator>>(istream &is, Day &day)
    {
        is >> day.d >> day.m >> day.y;
        if (!day.valid(day))
            throw invalid_argument("Invalid date");
        return is;
    }

    friend ostream &operator<<(ostream &os, Day day)
    {
        os << day.d << '/' << day.m << '/' << day.y;
        return os;
    }
    // các toán tử so sánh
    Day operator=(Day day)
    {
        d = day.d;
        m = day.m;
        y = day.y;
        return *this;
    }
    bool operator==(Day day) { return d == day.d && m == day.m && y == day.y; }
    bool operator!=(Day day) { return !(*this == day); }
    bool operator<(Day day) { return y < day.y || (y == day.y && (m < day.m || (m == day.m && d < day.d))); }
    bool operator>(Day day) { return !(*this < day || *this == day); }
    bool operator<=(Day day) { return *this < day || *this == day; }
    bool operator>=(Day day) { return !(*this < day); }
};

#endif