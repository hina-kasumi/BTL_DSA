#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#ifndef SinhVien_h
#define SinhVien_h

class SinhVien
{
private:
    string name;
    int maSV, age;
    float point;

public:
    SinhVien()
    {
        maSV = 0;
        name = "";
        age = 0;
        point = 0;
    }
    SinhVien(int maSV, string name, int age, float point)
    {
        this->maSV = maSV;
        this->name = name;
        this->age = age;
        this->point = point;
    }
    friend istream &operator>>(istream &is, SinhVien &sv)
    {
        is >> sv.maSV;
        is.ignore();
        getline(is, sv.name);
        is >> sv.age >> sv.point;
        return is;
    }
    friend ostream &operator<<(ostream &os, SinhVien sv)
    {
        os << setw(30) << sv.maSV
           << setw(30) << sv.name
           << setw(30) << sv.age
           << setw(30) << sv.point << endl;
        return os;
    }
    float getPoint() { return point; }
    string getName() { return name; }
    int getMaSV() { return maSV; }
    int getAge() { return age; }

    int static cmpName(SinhVien sv1, SinhVien sv2)
    {
        string name1 = sv1.name.substr(sv1.name.find_last_of(" ") + 1);
        string name2 = sv2.name.substr(sv2.name.find_last_of(" ") + 1);
        int cmp = name1.compare(name2);
        return cmp == 0 ? sv1.maSV < sv2.maSV : cmp < 0;
    }
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
             << setw(30) << "Tuoi"
             << setw(30) << "Diem" << endl;
        for (int i = 0; i < 120; i++)
            cout << "-";
        cout << endl;
    }
};

#endif