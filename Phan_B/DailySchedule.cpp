#include<iostream>
#include"TaskList.cpp"
#include"Day.cpp"
#include"Task.cpp"
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
    DailySchedule(Task task){
        day = task.getDay();
        taskList.addTask(task.getCongViec());
    }
    void setDay(Day day) {this->day = day;}

    // các method thêm xóa công việc
    void addTask(CongViec cv) {taskList.addTask(cv);}
    void removeTask(CongViec cv) {taskList.removeTask(cv);}

    // các method lấy ra danh sách công việc theo mức độ quan trọng hoặc trạng thái
    void getTaskByPriority(int tinhChatCongViec) {
        printLine();
        cout << day << ":" << endl;
        taskList.getTaskByPriority(tinhChatCongViec);
    }
    void getTaskByStatus(int trangThaiCongviec) {
        printLine();
        cout << day << ":" << endl;
        taskList.getTaskByStatus(trangThaiCongviec);
    }
    List<CongViec> getList() {return taskList.getList();}
    Day getDay() {return day;}
    TaskList getTaskList() {return taskList;}
    void print(){taskList.print();}

    int getListSize(){taskList.getSize();}
    bool containTask(CongViec cv){return taskList.containTask(cv);}








    // các toán tử so sánh
    bool operator==(DailySchedule ds) {return this->day == ds.day;}
    bool operator!=(DailySchedule ds) {return this->day != ds.day;}
    bool operator<(DailySchedule ds) {return this->day < ds.day;}
    bool operator>(DailySchedule ds) {return this->day > ds.day;}
    bool operator<=(DailySchedule ds) {return this->day <= ds.day;}
    bool operator>=(DailySchedule ds) {return this->day >= ds.day;}

    // ghi đè toán tử IO
    friend ostream &operator<<(ostream &os, DailySchedule dl){
        os << dl.day << endl;
        dl.taskList.print();
        return os;
    }
    friend istream &operator>>(istream &is, DailySchedule &dl){
        CongViec cv;
        is >> dl.day >> cv;
        dl.addTask(cv);
        return is;
    }
    void Output () {
        cout << this->day << endl;
        this->taskList.print();
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
};

#endif