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
        inorder(scheduleTree);
    }

    //Xem các công việc theo tính chất: rất quan trọng, quan trọng, …
    void viewTaskByPriority(string tinhChatCongViec) {
        getTaskByPriority(scheduleTree, tinhChatCongViec);
    }

    //Xem các công việc đã hoàn tất.
    void viewTaskDone(BST_Node *root) {
        getTaskByStatus(scheduleTree, "Hoan Thanh");
    }

    //Xem các công việc chưa thực hiện.
    void viewTaskNotDone(BST_Node *root) {
        getTaskByStatus(scheduleTree, "Chua Hoan Thanh");
    }

    //Xem các công việc từ ngày a đến ngày b.
    void viewTaskByDay(BST_Node *root,Day a,Day b) {
        
    }

    //Xóa hay điều chỉnh lịch công tác. Nếu sau khi điều chỉnh, ngày nào không còn việc phải làm sẽ xóa khỏi lịch công tác.
    void changeSchedule(Day day1, Day day2, CongViec cv) {
        
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
        cout << "1. nhap noi dung cong viec can lam theo ngay, theo gio\n"
             << "2. xem lich cong tac theo ngay yeu cau\n"
             << "3. xem cac cong viec theo tinh chat: rat quan trong, quan trong, ...\n"
             << "4. xem cac cong viec da hoan tat\n"
             << "5. xem cac cong viec chua thuc hien\n"
             << "6. xem cac cong viec tu ngay a den ngay b\n"
             << "7. xoa hay dieu chinh lich cong tac. Neu sau khi dieu chinh, ngay nao khong con viec phai lam se xoa khoi lich cong tac\n"
             << "8. lam sach\n"
             << "0. thoat\n";
        cin >> option;
        if (option == 1)
        {
            cout << "Nhap noi dung cong viec can lam theo ngay, theo gio: ";
            Task task;
            cin >> task;
            manager.addTask(task);
        }
        else if (option == 2)
        {
            cout << "Nhap ngay yeu cau: ";
            Day day;
            cin >> day;
            manager.viewTask(day);
        }
        else if (option == 3)
        {
            cout << "Nhap tinh chat cong viec: ";
            string tinhChatCongViec;
            cin >> tinhChatCongViec;
            manager.viewTaskByPriority(tinhChatCongViec);
        }
        else if (option == 4){manager.viewTaskDone(manager.getScheduleTree());}
        else if (option == 5){manager.viewTaskNotDone(manager.getScheduleTree());}
        else if (option == 6)
        {
            cout << "Nhap ngay dau va ngay cuoi: ";
            Day a, b;
            cin >> a >> b;
            manager.viewTaskByDay(manager.getScheduleTree(), a, b);
        }
        else if (option == 7)
        {
            cout << "Nhap ngay can dieu chinh, ngay moi va cong viec: ";
            Day day1, day2;
            CongViec cv;
            cin >> day1 >> day2 >> cv;
            manager.changeSchedule(day1, day2, cv);
        }
        else if (option == 8)
        {
            // lam sach man hinh
            system("cls");
        }
        // if (option > 0 && option < 9){
        //     cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //     cin.get();
        // }
    } while (option > 0 && option < 9);
    
    return 0;
}