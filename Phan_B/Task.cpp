#include<iostream>
#include"CongViec.cpp"
#include"Day.cpp"
using namespace std;

#ifndef Task_H
#define Task_H

class Task {
private:
    Day day;
    CongViec cv;
public:
    Task(){}
    friend istream &operator>>(istream &is, Task &t){
        is >> t.day >> t.cv;
        return is;
    }

    friend ostream &operator<<(ostream &os, Task dl){
        os << dl.day << endl << dl.cv;
        return os;
    }
    void setDay(Day day){this->day = day;}
    Day getDay(){return day;}
    CongViec getCongViec () {return cv;}

    // các toán tử so sánh
    bool operator==(Task ds) {return this->day == ds.day;}
    bool operator!=(Task ds) {return this->day != ds.day;}
    bool operator<(Task ds) {return this->day < ds.day;}
    bool operator>(Task ds) {return this->day > ds.day;}
    bool operator<=(Task ds) {return this->day <= ds.day;}
    bool operator>=(Task ds) {return this->day >= ds.day;}

};

#endif