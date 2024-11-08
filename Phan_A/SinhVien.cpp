#include <iostream>
#include <iomanip>
#include <string>
#include "Name.cpp"
#include "Birthday.cpp"
using namespace std;

#ifndef SinhVien_h
#define SinhVien_h

class SinhVien
{
private:
    FullName name;
    Birthday birthday;
    int maSV;
    float point;

public:
    SinhVien()
    {
        maSV = 0;
        point = 0;
    }
    friend istream &operator>>(istream &is, SinhVien &sv)
    {
        is >> sv.maSV;
        is.ignore();
        is >> sv.name;
        is >> sv.birthday >> sv.point;
        return is;
    }
    friend ostream &operator<<(ostream &os, SinhVien sv)
    {
        os << setw(30) << sv.maSV
           << setw(30) << sv.name
           << setw(20) << sv.birthday
           << setw(30) << sv.point << endl;
        return os;
    }
    float getPoint() { return point; }
    FullName getName() { return name; }
    int getMaSV() { return maSV; }
    Birthday getAge() { return birthday; }

    int static cmpName(SinhVien sv1, SinhVien sv2){return sv1.name < sv2.name;}
    int static cmpPoint(SinhVien sv1, SinhVien sv2)
    {
        if (sv1.point == sv2.point)
            return sv1.maSV < sv2.maSV;
        return sv1.point < sv2.point;
    }
    static bool equal(SinhVien sv1, SinhVien sv2)
    {
        return sv2.maSV == sv1.maSV;
    }
    static void printTable()
    {
        for (int i = 0; i < 120; i++)
            cout << "-";
        cout << endl;
        cout << setw(30) << "Ma SV"
             << setw(30) << "Ten"
             << setw(30) << "Sinh Nhat"
             << setw(30) << "Diem" << endl;
        for (int i = 0; i < 120; i++)
            cout << "-";
        cout << endl;
    }
    SinhVien operator=(SinhVien sv)
    {
        maSV = sv.maSV;
        name = sv.name;
        birthday = sv.birthday;
        point = sv.point;
        return *this;
    }
};

#endif