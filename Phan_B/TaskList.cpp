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
    void getTaskByPriority(int tinhChatCongViec) {
        for(List<CongViec>::iterator it = list.begin(); it != list.end(); ++it){
            if ((*it).getTinhChatCongViec() == tinhChatCongViec){
                cout << (*it);
            }
        }
    }

    void getTaskByStatus(int trangThaiCongviec) {
        for(List<CongViec>::iterator it = list.begin(); it != list.end(); ++it){
            if ((*it).getTrangThaiCongViec() == trangThaiCongviec){
                cout << (*it);
            }
        }
    }
    void print(){
        if(list.size() > 0)
            for(List<CongViec>::iterator it = list.begin(); it != list.end(); ++it)
                cout << (*it);
    }
    
    bool containTask(CongViec cv){
        for(List<CongViec>::iterator it = list.begin(); it != list.end(); ++it){
            if ((*it) == cv)
                return true;
        }
        return false;
    }

    void setDone (CongViec cv) {
        for(List<CongViec>::iterator it = list.begin(); it != list.end(); ++it){
            if ((*it) == cv){
                (*it).setDone();
                cout << "da danh dau hoan thanh.\n";
                return;
            }
        }
        cout << "khong tim thay cong viec ban muon danh dau.\n";
    }
};

#endif