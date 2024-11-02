#include <iostream>
#include"DailySchedule.cpp"
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
void insert(BST_Node *&curNode, DailySchedule val)
{
    if(curNode == nullptr){
        curNode = new BST_Node(val);
        return;
    }
    if (val.getDay() == curNode->data.getDay()){
        for(CongViec cv: val.getList())
            curNode->data.addTask(cv);
    }
    else if (val < curNode->data) 
        insert(curNode->left, val);
    else
        insert(curNode->right, val);
}

// tìm phần tử trong cây
BST_Node *find(BST_Node *curNode, DailySchedule value)
{
    if (curNode == nullptr || curNode->data == value)
        return curNode;
    else
        find((value < curNode->data)? curNode->left : curNode->right, value);
}

// tìm node có giá trị lớn nhất
DailySchedule max_node(BST_Node *curr)
{
    return curr->right ? max_node(curr->right) : curr->data;
}

// xóa node
void remove(BST_Node *&root, DailySchedule val)
{
    if (root == nullptr)
        return;
    if (root->data == val){
        if (root->data.getListSize() > 0){
            for(CongViec cv: val.getList())
                root->data.removeTask(cv);
        }
        if (root->data.getListSize() > 0);
        else if(!root->left) {
            BST_Node *p = root;
            root = root->right;
            delete p;
        }
        else if (!root->right){
            BST_Node *p = root;
            root = root->left;
            delete p;
        }
        else {
            root->data = max_node(root->left);
            remove(root->left, root->data);
        }
    }
}

// duyệt cây
void inorder(BST_Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
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
//         DailySchedule dl;
//         cin >> dl;
//         insert(tree, dl);
//     }
//     Day day;
//     cin >> day;
//     DailySchedule dl(day);
//     find(tree, dl)->data.clear();

//     inorder(tree);
    
//     return 0;
// }
