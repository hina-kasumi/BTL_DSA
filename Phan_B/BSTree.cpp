#include <iostream>
using namespace std;

#ifndef BST_H
#define BST_H

// Node class
template <class T>
class Node
{
private:
public:
    T data;
    Node<T> *left, *right;
    Node(T data = 0)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
// thêm hàm vào bằng đệ quy
template <class T>
void insert(Node<T> *&curNode, T val)
{
    if (curNode == nullptr)
        curNode = new Node<T>(val);
    else
        return insert(val < curNode->data ? curNode->left : curNode->right, val);
}

// tìm phần tử trong cây
template <class T>
Node<T> *find(Node<T> *curNode, T value)
{
    if (curNode == nullptr)
        return nullptr;
    if (value == curNode->data)
        return curNode;
    else if (value < curNode->data)
        return find(curNode->left, value);
    else if (value > curNode->data)
        return find(curNode->right, value);
}

// xóa node
template <class T>
T max_node(Node<T> *curr)
{
    return curr->right ? max_node(curr->right) : curr->data;
}

template <class T>
void remove(Node<T> *&root, T val)
{
    if (root == nullptr)
        return;
    if (root->data == val)
    {
        if (!root->left)
        {
            root = root->right;
        }
        else if (!root->right)
        {
            root = root->left;
        }
        else
        {
            root->data = max_node(root->left);
            remove(root->left, root->data);
        }
    }
    else
        remove(val < root->data ? root->left : root->right, val);
}

// duyệt cây
template <class T>
void inorder(Node<T> *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << ' ';
    inorder(root->right);
}

#endif
