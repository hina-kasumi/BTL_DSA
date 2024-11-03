#include<iostream>
#include"List.cpp"
#include"CongViec.cpp"
using namespace std;

#ifndef TASKLIST_H
#define TASKLIST_H

// đây là danh sách liên kiết chứa các công việc
class TaskList {
private:
    List<CongViec> list;
public:
    TaskList() {}
    int getSize(){return list.size();}
    void addTask(CongViec cv) {list.push(cv);}
    void removeTask(CongViec cv) {list.erase(cv);}

    List<CongViec> getList() {return list;}
    void getTaskByPriority(string tinhChatCongViec) {
        for(List<CongViec>::iterator it = list.begin(); it != list.end(); ++it){
            if ((*it).getTinhChatCongViec() == tinhChatCongViec){
                cout << (*it);
            }
        }
    }

    void getTaskByStatus(string trangThaiCongviec) {
        for(List<CongViec>::iterator it = list.begin(); it != list.end(); ++it){
            if ((*it).getTrangThaiCongViec().compare(trangThaiCongviec) == 0){
                cout << (*it);
            }
        }
    }
    void print(){
        if(list.size() > 0)
            for(List<CongViec>::iterator it = list.begin(); it != list.end(); ++it)
                cout << (*it);
    }
    
};

#endif

// int main(){
//     // freopen("dataTest.txt", "r", stdin);
//     int n;
//     cin >> n;
//     TaskList list;
//     for (int i = 0; i < n; i++)
//     {
//         CongViec cv;
//         cin >> cv;
//         list.addTask(cv);
//     }
//     // cout << (list.getList().begin().cur);
//     list.getTaskByPriority("Quan Trong");
//     cout << endl;
//     list.print();
//     cout << endl;
//     list.print();
    
// }
/*
4
3
A
lam A
Quan Trong
chua lam
5
B
lam B
binh thuong
lam roi
4
C
lam C
Quan Trong
da lam
9
D
lam D
rat quan trong
chua lam
*/