#include <iostream>
#include <exception>
#include <limits>
#include"BSTree.cpp"
#include"Day.cpp"
#include"DailySchedule.cpp"
#include"Task.cpp"
using namespace std;

//  Lớp quản lý và xử lý các yêu cầu của người dùng.
class DailyScheduleManager
{
private:
    BST_Node *scheduleTree;
public:
    DailyScheduleManager() {scheduleTree = nullptr;}
    ~DailyScheduleManager() {delete scheduleTree;}
    BST_Node *getScheduleTree() {return scheduleTree;}
    // Thêm một công việc vào lịch hàng ngày
    void addTask(Task dl) {
        insert(scheduleTree, dl);
    }

    // Xóa một công việc khỏi lịch hàng ngày
    void removeTask(Task dl) {
        remove(scheduleTree, dl);
    }
    
    // Xóa một ngày khỏi lịch
    void removeTask(Day day) {
        remove_day(scheduleTree, day);
    }

    // xem lịch công tác trong một ngày
    void viewTask(Day day) {
        BST_Node *node = find(scheduleTree, day);
        if(node)
            node->data.print();
    }

    void viewAllTask() {
        printTile();
        inorder(scheduleTree);
    }

    //Xem các công việc theo tính chất: rất quan trọng, quan trọng, …
    void viewTaskByPriority(int tinhChatCongViec) {
        printTile();
        getTaskByPriority(scheduleTree, tinhChatCongViec);
    }

    //Xem các công việc đã hoàn tất.
    void viewTaskDone(BST_Node *root) {
        printTile();
        getTaskByStatus(scheduleTree, 1);
    }

    //Xem các công việc chưa thực hiện.
    void viewTaskNotDone(BST_Node *root) {
        printTile();
        getTaskByStatus(scheduleTree, 0);
    }

    //Xem các công việc từ ngày a đến ngày b.
    void viewTaskByDay(BST_Node *root,Day a,Day b) {
        printTile();
        aPeriod(scheduleTree, a, b);
    }

    //Xóa hay điều chỉnh lịch công tác. Nếu sau khi điều chỉnh, ngày nào không còn việc phải làm sẽ xóa khỏi lịch công tác.
    void changeSchedule(Day day1, Day day2, CongViec cv) {
        // BST_Node *node1 = find(scheduleTree, day1);
    } 
};


int main()
{
    // 1.Nhập nội dung công việc cần làm theo ngày, theo giờ.
    // 2.Xem lịch công tác theo ngày yêu cầu.
    // 3.Xem các công việc theo tính chất: rất quan trọng, quan trọng, …
    // 4.Xem các công việc đã hoàn tất.
    // 5.Xem các công việc chưa thực hiện.
    // 6.Xem các công việc từ ngày a đến ngày b.
    // 7.Xóa hay điều chỉnh lịch công tác. Nếu sau khi điều chỉnh, ngày nào không còn việc phải làm sẽ xóa khỏi lịch công tác.
    DailyScheduleManager manager;
    int option = 0;
    do
    {
            cout << "0. thoat\n"
             << "1. nhap noi dung cong viec can lam theo ngay, theo gio\n"
             << "2. xem lich cong tac hien co\n"
             << "3. xem lich cong tac theo ngay yeu cau\n"
             << "4. xem cac cong viec theo tinh chat: rat quan trong, quan trong, ...\n"
             << "5. xem cac cong viec da hoan tat\n"
             << "6. xem cac cong viec chua thuc hien\n"
             << "7. xem cac cong viec tu ngay a den ngay b\n"
             << "8. xoa mot ngay cong tac\n"
             << "9. xoa mot cong viec\n"
             << "10. chuyen mot cong viec sang ngay khac\n"
             << "11. lam sach\n"
             << "Chon chuc nang: ";
        cin >> option;
        if (option == 1)
        {
            cout << "Nhap noi dung cong viec can lam theo ngay, theo gio:\n";
            Task task;
            cin >> task;
            manager.addTask(task);
        }
        else if (option == 2){
            manager.viewAllTask();
        }
        else if (option == 3)
        {
            cout << "Nhap ngay yeu cau: ";
            Day day;
            cin >> day;
            manager.viewTask(day);
        }
        else if (option == 4)
        {
            // Rất quan trọng, quan trọng, bình thường, không cần thiết
            cout << "Nhap tinh chat cong viec:\n"
            << "1. Rat quan trong\n"
            << "2. Quan trong\n"
            << "3. Binh thuong\n"
            << "4. Khong can thiet\n";
            int tinhChat;
            cin >> tinhChat;
            manager.viewTaskByPriority(tinhChat);
        }
        else if (option == 5){manager.viewTaskDone(manager.getScheduleTree());}
        else if (option == 6){manager.viewTaskNotDone(manager.getScheduleTree());}
        else if (option == 7)
        {
            Day a, b;
            cout << "Tu ngay: ";
            cin >> a ;
            cout << "Den ngay: ";
            cin >> b;
            manager.viewTaskByDay(manager.getScheduleTree(), a, b);
        }
        else if (option == 8)
        {
            cout << "Nhap ngay can xoa: ";
            Day day;
            cin >> day;
            manager.removeTask(day);
        }
        else if (option == 9)
        {
            cout << "Nhap cong viec can xoa: ";
            Task task;
            cin >> task;
            manager.removeTask(task);
        }
        else if (option == 10)
        {
            cout << "nhap cong viec can chuyen:\n";
            Task task;
            cin >> task;
            cout << "nhap ngay chuyen den:\n";
            Day day;
            cin >> day;
            manager.changeSchedule(task.getDay(), day, task.getCongViec());
        }
        else if (option == 11)
        {
            // lam sach man hinh
            system("cls");
        }
        
        if (option > 0 && option <= 11){
            cout << "An enter de tiep tuc...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

    } while (option > 0 && option <= 11);
    system("cls");
    return 0;
}