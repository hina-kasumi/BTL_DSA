#include <iostream>

#ifndef Linked_list_h
#define Linked_list_h

template <class T>
class node
{
private:
    T data;
    node<T> *prev, *next;

public:
    node(T data)
    {
        this->data = data;
        prev = next = nullptr;
    }
};

template <class T>
class linked_list
{
private:
    node<T> *header;
    node<T> *trailer;
    int num;
public:
    linked_list () {
        header = trailer = nullptr;
        num = 0;
    }
    int size(){return num}
    bool empty() {return !num}
    node<T> *frond(){return header;}
    node<T> *back(){return trailer;}
};

#endif