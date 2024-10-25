#include <bits/stdc++.h>
#include "SinhVien.cpp"
using namespace std;

int main()
{
    int option;
    vector<SinhVien> vectorSV;
    list<SinhVien> listSV;
    do
    {
        // 1. thêm danh sách sinh viên từ file
        // 2. theem sinh vien
        // 3. xoa sinh vien
        // 4. in danh sach sinh vien
        // 5. sap xep sinh vien theo diem
        // 6. sap xep sinh vien theo ten
        // 7. tim sinh vien theo so bao danh
        // 8. clear du lieu
        // 9. lam sach man hinh
        // 10. thoat
        cout << "1. them danh sach sinh vien tu file" << endl
             << "2. them sinh vien" << endl
             << "3. xoa sinh vien" << endl
             << "4. in danh sach sinh vien" << endl
             << "5. sap xep sinh vien theo diem" << endl
             << "6. sap xep sinh vien theo ten" << endl
             << "7. tim sinh vien theo so bao danh" << endl
             << "8. clear du lieu" << endl
             << "9. lam sach man hinh" << endl
             << "10. thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> option;
        if (option == 1)
        {
            // them danh sach sinh vien tu file
            string fileName;
            cout << "Nhap ten file: ";
            cin >> fileName;
            ifstream file(fileName);
            if (file.is_open())
            {
                int n;
                file >> n;
                while (n--)
                {
                    SinhVien sv;
                    file >> sv;
                    if (sv.getMaSV() % 2 == 0)
                        vectorSV.push_back(sv);
                    else
                        listSV.push_back(sv);
                }
                file.close();
                cout << "Da them sinh vien tu file" << endl;
            }
            else
            {
                cout << "Khong the mo file" << endl;
            }
        }
        else if (option == 2)
        {
            // them sinh vien
            cout << "thong tin can them gom: maSV, tenSV, tuoiSV, DiemSv" << endl;
            SinhVien sv;
            cin >> sv;
            if (sv.getMaSV() % 2 == 0)
                vectorSV.push_back(sv);
            else
                listSV.push_back(sv);
            cout << "Da them sinh vien" << endl;
        }
        else if (option == 3)
        {
            // xoa sinh vien
            int maSV;
            cout << "Nhap ma sinh vien can xoa: ";
            cin >> maSV;
            bool isDeleted = false;
            if (maSV % 2 == 0)
            {
                for (int i = 0; i < vectorSV.size(); i++)
                {
                    if (vectorSV[i].getMaSV() == maSV)
                    {
                        vectorSV.erase(vectorSV.begin() + i);
                        isDeleted = true;
                        cout << "Da xoa sinh vien" << endl;
                        break;
                    }
                }
            }
            else
            {
                for (list<SinhVien>::iterator it = listSV.begin(); it != listSV.end(); it++)
                {
                    if (it->getMaSV() == maSV)
                    {
                        isDeleted = true;
                        cout << "Da xoa sinh vien" << endl;
                        listSV.erase(it);
                        break;
                    }
                }
            }
            if (!isDeleted)
                cout << "Khong tim thay sinh vien" << endl;
        }
        else if (option == 4)
        {
            // in danh sach sinh vien
            int soLuongSinhVien = vectorSV.size() + listSV.size();
            cout << "Danh sach sinh vien co ma sinh vien la so chan:" << endl;
            SinhVien::printTable();
            for (int i = 0; i < vectorSV.size(); i++)
            {
                cout << vectorSV[i] << endl;
            }
            cout << "Danh sach sinh vien co ma sinh vien la so le:" << endl;
            SinhVien::printTable();
            for (list<SinhVien>::iterator it = listSV.begin(); it != listSV.end(); it++)
            {
                cout << *it << endl;
            }
            cout << "Tong so luong sinh vien: " << soLuongSinhVien << endl;
        }
        else if (option == 5)
        {
            // sap xep sinh vien theo diem
            sort(vectorSV.begin(), vectorSV.end(), SinhVien::cmpPoint);
            listSV.sort(SinhVien::cmpPoint);
            cout << "Sinh vien da duoc sap xep theo diem" << endl;
        }
        else if (option == 6)
        {
            // sap xep sinh vien theo ten
            sort(vectorSV.begin(), vectorSV.end(), SinhVien::cmpName);
            listSV.sort(SinhVien::cmpName);
            cout << "Sinh vien da duoc sap xep theo ten" << endl;
        }
        else if (option == 7)
        {
            // tim sinh vien theo so bao danh
            int maSV;
            cout << "Nhap ma sinh vien can tim: ";
            cin >> maSV;
            if (maSV % 2 == 0)
            {
                for (int i = 0; i < vectorSV.size(); i++)
                {
                    if (vectorSV[i].getMaSV() == maSV)
                    {
                        SinhVien::printTable();
                        cout << vectorSV[i] << endl;
                        break;
                    }
                }
            }
            else
            {
                bool isFound = false;
                for (list<SinhVien>::iterator it = listSV.begin(); it != listSV.end(); it++)
                {
                    if (it->getMaSV() == maSV)
                    {
                        SinhVien::printTable();
                        isFound = true;
                        cout << *it << endl;
                        break;
                    }
                }
                if (!isFound)
                    cout << "Khong tim thay sinh vien" << endl;
            }
        }
        else if (option == 8)
        {
            // clear du lieu
            vectorSV.clear();
            listSV.clear();
            cout << "Da xoa toan bo du lieu sinh vien" << endl;
        }
        else if (option == 9)
        {
            // lam sach man hinh
            system("cls");
        }
        if (option > 0 && option < 10)
            cout << "An enter de tiep tuc...";
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    } while (option > 0 && option < 10);
}