#include <iostream>
#include "DailySchedule.cpp"
#include "Task.cpp"
using namespace std;

#ifndef BST_H
#define BST_H
// Node class

class BST_Node
{
private:
public:
    DailySchedule data;
    BST_Node *left, *right;
    BST_Node(DailySchedule data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
// thêm hàm vào bằng đệ quy
void insert(BST_Node *&curNode, Task val)
{
    if (curNode == nullptr)
    {
        curNode = new BST_Node(val);
        return;
    }
    if (val.getDay() == curNode->data.getDay())
    {
        curNode->data.addTask(val.getCongViec());
    }
    else if (val.getDay() < curNode->data.getDay())
        insert(curNode->left, val);
    else
        insert(curNode->right, val);
}

// tìm phần tử trong cây
BST_Node *find(BST_Node *curNode, Day day)
{
    if (curNode == nullptr || curNode->data.getDay() == day)
        return curNode;
    else
        return find((day < curNode->data.getDay()) ? curNode->left : curNode->right, day);
}

// tìm node có giá trị lớn nhất
DailySchedule max_node(BST_Node *curr)
{
    return curr->right ? max_node(curr->right) : curr->data;
}
void remove_day (BST_Node *&root, Day day) {
    if (root == nullptr)
        return;
    if (root->data.getDay() == day){
        if(!root->left && !root->right){
            root = nullptr;
            return;
        }
        if (!root->left){
            BST_Node *p = root;
            root->right;
            p = nullptr;
            // delete p;
        }
        else if (!root->right){
            BST_Node *p = root;
            root = root->left;
            p = nullptr;
            // delete p;
        }
        else {
            root->data = max_node(root->left);
            remove_day(root->left, root->data.getDay());
        }
    }
    else
        remove_day(day < root->data.getDay()?root->left:root->right, day);
}

// xóa node
void remove(BST_Node *&root, Task val)
{
    BST_Node *node = find(root, val.getDay());
    if (node == nullptr)
        return;
    node->data.removeTask(val.getCongViec());
    if (node->data.getList().size()==0)
        remove_day(root, val.getDay());
}

// duyệt cây
void inorder(BST_Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    printLine();
    cout << root->data.getDay() << ":" << endl;
    root->data.print();
    inorder(root->right);
}

void getTaskByPriority(BST_Node *root, string tinhChatCongViec){
    if (!root)
        return;
    getTaskByPriority(root->left, tinhChatCongViec);
    root->data.getTaskByPriority(tinhChatCongViec);
    getTaskByPriority(root->right, tinhChatCongViec);
}
void getTaskByStatus(BST_Node *root, string trangThaiCongViec){
    if (!root)
        return;
    getTaskByStatus(root->left, trangThaiCongViec);
    root->data.getTaskByStatus(trangThaiCongViec);
    getTaskByStatus(root->right, trangThaiCongViec);
}

#endif

// int main()
// {
//     freopen("dataTest.txt", "r", stdin);
//     int n;
//     cin >> n;

//     BST_Node *tree = nullptr;
//     for (int i = 0; i < n; i++)
//     {
//         Task dl;
//         cin >> dl;
//         insert(tree, dl);
//     }
//     inorder(tree);
//     Task task;
//     cin >> task;
//     // DailySchedule dl(day);
//     // dl.Output();
//     remove(tree, task);
//     cout << endl << "-------------------------" << endl;
//     // cout << "data:\n" << (find(tree, dl)->data) << endl;
//     inorder(tree);

//     return 0;
// }
