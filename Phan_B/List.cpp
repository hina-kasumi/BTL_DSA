#include <iostream>
using namespace std;

#ifndef list_h
#define list_h

// Node class
template <class T>
class list_node
{
public:
    T data;
    list_node *prev;
    list_node *next;

    list_node(T data, list_node *prev = nullptr, list_node *next = nullptr)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

// Iterator class
template <class T>
class list_iterator
{
public:
    list_node<T> *cur;
    list_iterator(list_node<T> *cur) { this->cur = cur; }
    T &operator*() { return cur->data; }
    bool operator!=(list_iterator it) { return cur != it.cur; }
    list_iterator<T> operator++(int)
    {
        cur = cur->next;
        return cur;
    }
    list_iterator<T> operator++()
    {
        list_iterator<T> it = cur;
        cur = cur->next;
        return it;
    }
    list_iterator<T> operator--(int)
    {
        cur = cur->prev;
        return cur;
    }
    list_iterator<T> operator--()
    {
        list_iterator<T> it = cur;
        cur = cur->prev;
        return it;
    }
};

// Linked list class
template <class T>
class List
{
private:
    list_node<T> *head;
    list_node<T> *tail;
    int n = 0;
    void push_back(T x)
    {
        if (n == 0) head = tail = new list_node<T>(x);
        else tail = tail->next = new list_node<T>(x, tail);
        n++;
    }
    void push_front(T x)
    {
        if (n == 0) head = tail = new list_node<T>(x);
        else head = head->prev = new list_node<T>(x, nullptr, head);
        n++;
    }
public:
    void pop_front()
    {
        if (!head)
            return;
        n--;
        if (head == tail){
            head = tail = nullptr;
            return;
        }
        list_node<T> *p = head;
        head->next->prev = nullptr;
        head = head->next;
        delete p;
    }
    List()
    {
        head = tail = nullptr;
        n = 0;
    }
    ~List(){while (n) pop_front();}
    bool empty() { return n == 0; }
    int size() { return n; }
    T front() { return head->data; }
    T back() { return tail->data; }
    // void clear (){while (n) pop_front();}
    void push(T x)
    {
        if (n == 0) push_back(x);
        else if (x <= head->data) push_front(x);
        else if (x >= tail->data) push_back(x);
        else
        {
            list_node<T> *cur = head->next;
            list_node<T> *prevNode = head;
            while (cur->next != nullptr && x > cur->data)
            {
                prevNode = cur;
                cur = cur->next;
            }
            list_node<T> *newNode = new list_node<T>(x, cur->prev, cur);
            // cout << cur->prev << ' ' << cur->next << '\n';
            prevNode->next = newNode;
            cur->prev = newNode;
            n++;
        }
    }

    void erase(T x)
    {
        if (n == 0)
            return;
        if (n == 1 && head->data == x)
            return pop_front();
        list_node<T> *p = head;
        while (p->next != nullptr && p->data != x)
            p = p->next;
        if (p == nullptr)
            return;
        if (p == head)
        {
            head = head->next;
            head->prev = nullptr;
        }
        else if (p == tail)
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
        }
        delete p;
        n--;
    }

    typedef list_iterator<T> iterator;
    iterator begin() { return head; }
    iterator end() { return tail->next; }
    iterator rbegin() { return tail; }
    iterator rend() { return head->prev; }

    void erase(iterator it)
    {
        if (it.cur == head)
        {
            head = head->next;
            head->prev = nullptr;
        }
        else if (it.cur == tail)
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
        {
            it.cur->prev->next = it.cur->next;
            it.cur->next->prev = it.cur->prev;
        }
        delete it.cur;
        n--;
    }
};

#endif