#include<iostream>
#include"TaskList.cpp"
#include"Day.cpp"
using namespace std;

#ifndef DAILYSCHEDULE_H
#define DAILYSCHEDULE_H

// đây là lịch hàng ngày chứa ngày nào có những công việc gì trong ngày đó
class DailySchedule {
private:
    Day day;
    TaskList taskList;
public:
    DailySchedule(Day day) {this->day = day;}
    DailySchedule(){}
    void setDay(Day day) {this->day = day;}

    // các method thêm xóa công việc
    void addTask(CongViec cv) {taskList.addTask(cv);}
    void removeTask(CongViec cv) {taskList.removeTask(cv);}

    // các method lấy ra danh sách công việc theo mức độ quan trọng hoặc trạng thái
    void getTaskByPriority(string tinhChatCongViec) {taskList.getTaskByPriority(tinhChatCongViec);}
    void getTaskByStatus(string trangThaiCongviec) {return taskList.getTaskByStatus(trangThaiCongviec);}
    List<CongViec> getList() {return taskList.getList();}
    Day getDay() {return day;}
    TaskList getTaskList() {return taskList;}

    int getListSize(){taskList.getList().size();}

    // các toán tử so sánh
    bool operator==(DailySchedule ds) {return day == ds.day;}
    bool operator!=(DailySchedule ds) {return day != ds.day;}
    bool operator<(DailySchedule ds) {return day < ds.day;}
    bool operator>(DailySchedule ds) {return day > ds.day;}
    bool operator<=(DailySchedule ds) {return day <= ds.day;}
    bool operator>=(DailySchedule ds) {return day >= ds.day;}

    // ghi đè toán tử IO
    friend ostream &operator<<(ostream &os, DailySchedule dl){
        os << dl.day << endl;
        dl.getList().print();
        return os;
    }
    friend istream &operator>>(istream &is, DailySchedule &dl){
        CongViec cv;
        is >> dl.day >> cv;
        dl.addTask(cv);
        return is;
    }
    static DailySchedule Input () {
        Day day;
        cin >> day;
        CongViec cv;
        cin >> cv;
        DailySchedule dl(day);
        dl.addTask(cv);
        return dl;
    }
    void clear(){
        taskList.clear();
    }
};

#endif

// int main () {

//     freopen("dataTest.txt", "r", stdin);
//     int n;
//     cin >> n;
//     Day day;
//     cin >> day;
//     DailySchedule list(day);
//     for (int i = 0; i < n; i++)
//     {
//         CongViec cv;
//         cin >> cv;
//         list.addTask(cv);
//     }
//     // cout << (list.getList().begin().cur);
//     cout << day << endl;
//     list.getTaskByPriority("Quan Trong");
//     cout << endl;
//     list.getList().print();
    

// }