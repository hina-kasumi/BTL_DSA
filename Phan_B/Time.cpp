#include <iostream>
#include<exception>
#include <stdexcept>
#include<string>
using namespace std;

#ifndef TIME_H
#define TIME_H


class Time {
private:
    int day, hour;
public:
    Time (int day = 0, int hour = 0){
        if(hour < 0 || hour >= 24 || day >= 30 || day < 0)
            throw std::runtime_error("Invalid time provided");
        this->day = day;
        this->hour = hour;
    }


    void setHour (int hour){
        if( hour < 0 || hour >= 24)
            throw std::runtime_error("Invalid time provided");
        this->hour = hour;
    }

    void setDay(int day){
        if(day >= 30 || day < 0)
            throw std::runtime_error("Invalid time provided");
        this->day = day;
    }

    friend istream &operator>>(istream& is, Time &t){
        is >> t.day >> t.hour;

        return is;
    }

    friend ostream &operator<<(ostream& os, Time t){
        os << t.day << ":" << t.hour;

        return os;
    }

    //ghi de toan tu so sanh
    bool operator<(Time t){
        if(this->day < t.day)
            return true;
        if(this->day == t.day && this->hour < t.hour)
            return true;
        return false;
    }
    bool operator>(Time t){
        if(this->day > t.day)
            return true;
        if(this->day == t.day && this->hour > t.hour)
            return true;
        return false;
    }

    bool operator==(Time t){
        return this->day == t.day && this->hour == t.hour;
    }
    bool operator!=(Time t){
        return !(*this == t);
    }
    bool operator<=(Time t){
        return *this < t || *this == t;
    }
    bool operator>=(Time t){
        return *this > t || *this == t;
    }
    Time operator+(Time t){
        Time res;
        res.day = this->day + t.day;
        res.hour = this->hour + t.hour;
        if(res.hour >= 24){
            res.hour -= 24;
            res.day++;
        }
        return res;
    }
    Time operator-(Time t){
        Time res;
        res.day = this->day - t.day;
        res.hour = this->hour - t.hour;
        if(res.hour < 0){
            res.hour += 24;
            res.day--;
        }
        return res;
    }

    Time operator=(Time t){
        this->day = t.day;
        this->hour = t.hour;
        return *this;
    }
};

#endif