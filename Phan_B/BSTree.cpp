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
    Node(T data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

// BSTree class
template <class T>
class BSTree
{
private:
    Node<T>* root;

public:
    BSTree()
    {
        this->root = nullptr;
    }

    // thêm hàm vào bằng đệ quy
    void insert(Node<T>* &curNode, T val)
    {
        Node<T> *newNode = new Node<T>(val);
        if (curNode == nullptr)
            curNode = newNode;
        else if (val < curNode->data)
            insert(curNode->left, val);
        else if (val > curNode->data)
            insert(curNode->right, val);
    }

    // tìm phần tử trong cây
    Node<T> *find(Node<T> *curNode, T value)
    {
        if (root == nullptr)
            return nullptr;
        if (value == curNode->data)
            return curNode;
        else if (value < curNode->data)
            return find(curNode->left, value);
        else if (value > curNode->data)
            return find(curNode->right, value);
    }

    // duyệt cây
    void PreOder(Node<T>* root)
    {
        if (root == nullptr)
            return;
        cout << root->data << ' ';
        PreOder(root->left);
        PreOder(root->right);
    }

    Node<T>* &getRoot()
    {
        return root;
    }
};

#endif