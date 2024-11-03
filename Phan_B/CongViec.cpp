#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
#include <iomanip>
// #include "Time.cpp"
using namespace std;

#ifndef CONGVIEC_H
#define CONGVIEC_H

string tinhChat(int tinhChatCongViec){
    switch (tinhChatCongViec)
    {
        case 1: return "Rat Quan Trong";
        case 2: return "Quan Trong";
        case 3: return "Binh Thuong";
        case 4: return "Khong Can Thiet";
        default: return "Khong Xac Dinh";
    }
}

string trangThai(int trangThaiCongViec){
    switch (trangThaiCongViec)
    {
        case 0: return "Chua Hoan Thanh";
        case 1: return "Hoan Thanh";
        default: return "Khong Xac Dinh";
    }
}

//đây là công việc sẽ đc chứa trong TaskList và DailySchedule
class CongViec
{
private:
    int gioBatDau;
    string tenCongViec;
    string noiDungCongviec;
    int tinhChatCongViec;//rat quan trong, quan trong, binh thuong, khong can thiet
    int trangThaiCongviec;

public:
    CongViec(int gioBatDau, string tenCongViec, string noiDungCongviec)
    {
        this->gioBatDau = gioBatDau;
        this->tenCongViec = tenCongViec;
        this->noiDungCongviec = noiDungCongviec;
        this->tinhChatCongViec = 0;
        this->trangThaiCongviec = 0;
    }

    CongViec()
    {
        this->gioBatDau = 0;
        this->tenCongViec = "";
        this->noiDungCongviec = "";
        this->tinhChatCongViec = 0;
        this->trangThaiCongviec = 0;
    }   

    //toan tu nhap xuat
    friend istream &operator>>(istream &is, CongViec &cv)
    {
        is >> cv.gioBatDau;
        is.ignore();
        getline(is, cv.tenCongViec);
        getline(is, cv.noiDungCongviec); 
        is >> cv.tinhChatCongViec >> cv.trangThaiCongviec;

        return is;
    }

    friend ostream &operator<<(ostream &os, CongViec cv)
    {
        os << setw(15) << cv.gioBatDau << '|'
           << setw(20) << cv.tenCongViec << '|'
           << setw(20) << cv.noiDungCongviec << '|'
           << setw(20) << tinhChat(cv.tinhChatCongViec) << '|'
           << setw(20) << trangThai(cv.trangThaiCongviec) << endl;

        return os;
    }

    //getter and setter
    int getTime(){return gioBatDau;}
    int getTrangThaiCongViec(){return trangThaiCongviec;}
    int getTinhChatCongViec(){return tinhChatCongViec;}

    void setDone(){trangThaiCongviec = 1;}

    void setRatQuanTrong(){tinhChatCongViec = 1;}
    void setQuanTrong(){tinhChatCongViec = 2;}   
    void setBinhThuong(){tinhChatCongViec = 3;}
    void setKhongCanThiet(){tinhChatCongViec = 4;}


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

void printTile(){
    printLine();
    cout << setw(15) << "Gio Bat Dau" << '|'
         << setw(20) << "Ten Cong Viec" << '|'
         << setw(20) << "Noi Dung Cong Viec" << '|'
         << setw(20) << "Tinh Chat Cong Viec" << '|'
         << setw(20) << "Trang Thai Cong Viec" << endl;
    printLine();
}

#endif