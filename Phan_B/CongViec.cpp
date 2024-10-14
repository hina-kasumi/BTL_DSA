#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
#include <iomanip>
#include "Time.cpp"
using namespace std;

#ifndef CONGVIEC_H
#define CONGVIEC_H

class CongViec
{
private:
    Time gioBatDau;
    string tenCongViec;
    string noiDungCongviec;
    string tinhChatCongViec;//rat quan trong, quan trong, binh thuong, khong can thiet
    string trangThaiCongviec;

public:
    CongViec(Time gioBatDau, string tenCongViec, string noiDungCongviec)
    {
        this->gioBatDau = gioBatDau;
        this->tenCongViec = tenCongViec;
        this->noiDungCongviec = noiDungCongviec;
        this->tinhChatCongViec = "";
        setNotStarted();
    }

    CongViec()
    {
        this->gioBatDau = Time();
        this->tenCongViec = "";
        this->noiDungCongviec = "";
        this->tinhChatCongViec = "";
        setNotStarted();
    }   

    friend istream &operator>>(istream &is, CongViec &cv)
    {
        is >> cv.gioBatDau >> cv.tenCongViec >> cv.noiDungCongviec;
        return is;
    }

    friend ostream &operator<<(ostream &os, CongViec cv)
    {
        os << setw(20) << cv.gioBatDau << '|'
           << setw(20) << cv.tenCongViec << '|'
           << setw(20) << cv.noiDungCongviec << '|'
           << setw(20) << cv.tinhChatCongViec << '|'
           << setw(20) << cv.trangThaiCongviec << '|';

        return os;
    }

    Time getTime()
    {
        return gioBatDau;
    }

    string getTrangThaiCongViec(){
        return trangThaiCongviec;
    }

    void setDone(){
        trangThaiCongviec = "Hoan Thanh";
    }

    void setWorking (){
        trangThaiCongviec = "Dang Lam";
    }

    void setNotStarted (){
        trangThaiCongviec = "Chua Lam";
    }

    void setQuanTrong(){
        tinhChatCongViec = "Rat Quan Trong";
    }

    void setKhongCanThiet(){
        tinhChatCongViec = "Khong Can Thiet";
    }

    void setBinhThuong(){
        tinhChatCongViec = "Binh Thuong";
    }

    void setQuanTrong(){
        tinhChatCongViec = "Quan Trong";
    }   


    // ghi de toan tu
    CongViec operator=(const CongViec cv)
    {
        this->gioBatDau = cv.gioBatDau;
        this->tenCongViec = cv.tenCongViec;
        this->noiDungCongviec = cv.noiDungCongviec;
        this->tinhChatCongViec = cv.tinhChatCongViec;
        this->trangThaiCongviec = cv.trangThaiCongviec;
        return *this;
    }

    bool operator==(const CongViec cv)
    {
        return this->gioBatDau == cv.gioBatDau && this->tenCongViec == cv.tenCongViec && this->noiDungCongviec == cv.noiDungCongviec;
    }

    bool operator!=(const CongViec cv)
    {
        return !(*this == cv);
    }

    //ghi de toan tu so sanh
    

};

#endif