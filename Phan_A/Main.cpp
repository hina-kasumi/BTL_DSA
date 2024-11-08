#include <bits/stdc++.h>
#include "SinhVien.cpp"
using namespace std;

class Manager
{
private:
    vector<SinhVien> vectorSV;
public:
    static void printOption()
    {
        cout << "1. them danh sach sinh vien tu file" << endl
             << "2. them sinh vien" << endl
             << "3. xoa sinh vien" << endl
             << "4. in danh sach sinh vien" << endl
             << "5. sap xep sinh vien theo diem" << endl
             << "6. sap xep sinh vien theo ten" << endl
             << "7. tim sinh vien theo ma sinh vien" << endl
             << "8. clear du lieu" << endl
             << "9. sua thong tin sinh vien" << endl
             << "10. lam sach man hinh" << endl
             << "11. thoat" << endl;
        cout << "Nhap lua chon: ";
    }
    void addFromFile(string fileName)
    {
        ifstream file(fileName);
        if (file.is_open())
        {
            int n;
            file >> n;
            while (n--)
            {
                SinhVien sv;
                file >> sv;
                vectorSV.push_back(sv);
            }
            file.close();
            cout << "Da them sinh vien tu file" << endl;
        }
        else
        {
            cout << "Khong the mo file" << endl;
        }
    }
    void addSinhVien(SinhVien sv)
    {
        vectorSV.push_back(sv);
        cout << "Da them sinh vien" << endl;
    }
    void deleteSinhVien(int maSV)
    {
        bool isDeleted = false;
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
        if (!isDeleted)
            cout << "Khong tim thay sinh vien" << endl;
    }
    void printSinhVien()
    {
        cout << "Danh sach sinh vien:" << endl;
        SinhVien::printTable();
        for (int i = 0; i < vectorSV.size(); i++)
        {
            cout << vectorSV[i] << endl;
        }
    }
    void sortPoint()
    {
        sort(vectorSV.begin(), vectorSV.end(), SinhVien::cmpPoint);
        cout << "Sinh vien da duoc sap xep theo diem" << endl;
    }
    void sortName()
    {
        sort(vectorSV.begin(), vectorSV.end(), SinhVien::cmpName);
        cout << "Sinh vien da duoc sap xep theo ten" << endl;
    }
    void findSinhVien(int maSV)
    {
        bool isFound = false;
        for (int i = 0; i < vectorSV.size(); i++)
        {
            if (vectorSV[i].getMaSV() == maSV)
            {
                SinhVien::printTable();
                cout << vectorSV[i] << endl;
                isFound = true;
                break;
            }
        }
        if (!isFound)
            cout << "Khong tim thay sinh vien" << endl;
    }
    void clearData()
    {
        vectorSV.clear();
        cout << "Da xoa toan bo du lieu sinh vien" << endl;
    }
    void editSinhVien(int maSV)
    {
        bool isFound = false;
        for (int i = 0; i < vectorSV.size(); i++)
        {
            if (vectorSV[i].getMaSV() == maSV)
            {
                cout << "thong tin can sua gom: maSV, hotenSV, ngaySinhNhat, DiemSv" << endl;
                SinhVien sv;
                cin >> sv;
                isFound = true;
                if (sv.getMaSV() == vectorSV[i].getMaSV()){
                    vectorSV[i] = sv;
                    
                    cout << "Da sua sinh vien" << endl;
                    break;
                }
                else 
                    cout << "Ma sinh vien khong duoc sua" << endl;
                
            }
        }
        if (!isFound)
            cout << "Khong tim thay sinh vien" << endl;
    }
};

int main()
{
    int option;
    Manager manager;
    do
    {
        Manager::printOption();
        cin >> option;
        if (option == 1)
        {
            // them danh sach sinh vien tu file
            string fileName;
            cout << "Nhap ten file: ";
            cin >> fileName;
            manager.addFromFile(fileName);
        }
        else if (option == 2)
        {
            // them sinh vien
            cout << "thong tin can them gom: maSV, hotenSV, ngaySinhNhat, DiemSv" << endl;
            SinhVien sv;
            cin >> sv;
            manager.addSinhVien(sv);
        }
        else if (option == 3)
        {
            // xoa sinh vien
            int maSV;
            cout << "Nhap ma sinh vien can xoa: ";
            cin >> maSV;
            manager.deleteSinhVien(maSV);
        }
        else if (option == 4)
        {
            // in danh sach sinh vien
            manager.printSinhVien();
        }
        else if (option == 5)
        {
            // sap xep sinh vien theo diem
            manager.sortPoint();
        }
        else if (option == 6)
        {
            // sap xep sinh vien theo ten
            manager.sortName();
        }
        else if (option == 7)
        {
            // tim sinh vien theo so bao danh
            int maSV;
            cout << "Nhap ma sinh vien can tim: ";
            cin >> maSV;
            manager.findSinhVien(maSV);
        }
        else if (option == 8)
        {
            // clear du lieu
            manager.clearData();
        }
        else if (option == 9){
            cout << "nhap ma sinh vien muon sua thong tin: ";
            int maSV;
            cin >> maSV;
            manager.editSinhVien(maSV);
        }
        else if (option == 10)
        {
            // lam sach man hinh
            system("cls");
        }
        if (option > 0 && option < 11){
            cout << "An enter de tiep tuc...";

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }
    } while (option > 0 && option < 11);
    system("cls");
}