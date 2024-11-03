#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
#include <iomanip>
// #include "Time.cpp"
using namespace std;

#ifndef CONGVIEC_H
#define CONGVIEC_H


//đây là công việc sẽ đc chứa trong TaskList và DailySchedule
class CongViec
{
private:
    int gioBatDau;
    string tenCongViec;
    string noiDungCongviec;
    string tinhChatCongViec;//rat quan trong, quan trong, binh thuong, khong can thiet
    string trangThaiCongviec;

public:
    CongViec(int gioBatDau, string tenCongViec, string noiDungCongviec)
    {
        this->gioBatDau = gioBatDau;
        this->tenCongViec = tenCongViec;
        this->noiDungCongviec = noiDungCongviec;
        this->tinhChatCongViec = "";
        setNotDone();
    }

    CongViec()
    {
        this->gioBatDau = 0;
        this->tenCongViec = "";
        this->noiDungCongviec = "";
        this->tinhChatCongViec = "";
        setNotDone();
    }   

    //toan tu nhap xuat
    friend istream &operator>>(istream &is, CongViec &cv)
    {
        is >> cv.gioBatDau;
        is.ignore();
        getline(is, cv.tenCongViec);
        getline(is, cv.noiDungCongviec); 
        getline(is, cv.tinhChatCongViec); 
        getline(is, cv.trangThaiCongviec);

        return is;
    }

    friend ostream &operator<<(ostream &os, CongViec cv)
    {
        os << setw(15) << cv.gioBatDau << '|'
           << setw(20) << cv.tenCongViec << '|'
           << setw(20) << cv.noiDungCongviec << '|'
           << setw(20) << cv.tinhChatCongViec << '|'
           << setw(20) << cv.trangThaiCongviec << endl;

        return os;
    }

    //getter and setter
    int getTime(){return gioBatDau;}
    string getTrangThaiCongViec(){return trangThaiCongviec;}
    string &getTinhChatCongViec(){return this->tinhChatCongViec;}

    void setDone(){trangThaiCongviec = "Hoan Thanh";}
    void setNotDone (){trangThaiCongviec = "Chua Hoan Thanh";}

    void setRatQuanTrong(){tinhChatCongViec = "Rat Quan Trong";}
    void setKhongCanThiet(){tinhChatCongViec = "Khong Can Thiet";}
    void setBinhThuong(){tinhChatCongViec = "Binh Thuong";}
    void setQuanTrong(){tinhChatCongViec = "Quan Trong";}   


    // ghi de toan tu gan
    CongViec operator=(const CongViec cv)
    {
        this->gioBatDau = cv.gioBatDau;
        this->tenCongViec = cv.tenCongViec;
        this->noiDungCongviec = cv.noiDungCongviec;
        this->tinhChatCongViec = cv.tinhChatCongViec;
        this->trangThaiCongviec = cv.trangThaiCongviec;
        return *this;
    }

    //ghi de toan tu so sanh
    bool operator<(const CongViec cv){return this->gioBatDau < cv.gioBatDau;}
    bool operator>(const CongViec cv){return this->gioBatDau > cv.gioBatDau;}
    bool operator<=(const CongViec cv){return this->gioBatDau <= cv.gioBatDau;}
    bool operator>=(const CongViec cv){return this->gioBatDau >= cv.gioBatDau;}
    bool operator==(const CongViec cv){return this->gioBatDau == cv.gioBatDau;}
    bool operator!=(const CongViec cv){return this->gioBatDau != cv.gioBatDau;}
};

void printLine(){
    for (int i = 0; i <= 100; i++)
    {
        cout << '-';
    }
    cout << endl;
}

#endif