#include <iostream>
using namespace std;

#ifndef Linked_list_h
#define Linked_list_h

template <class T>
class node
{
private:
public:
    T data;
    node<T> *next;
    node(T data = 0, node<T> *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
    T &getData () {return data;}
};

//iterator
template <class T>
class list_iterator {
    public:
    node<T>* cur;
    list_iterator(node<T> *c = 0) {cur = c;}
    T &operator*() {return cur->data;}
    bool operator!=(list_iterator<T> it1) { return cur != it1.cur;}
    list_iterator<T> operator++ (int) {
        cur = cur->next;
        return cur;
    }
    list_iterator<T> operator++() {
        list_iterator<T> it1 = cur;
        cur = cur->next;
        return it1;
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
    ~linked_list() {while(num)pop_front();}
    int size(){return num;}
    bool empty() {return num == 0;}
    T &front(){return header->getData();}
    T &back(){return trailer->getData();}
    void push_front (T val) {
        if (num == 0)
            header = trailer = new node<T>(val);
        else
            header = new node<T>(val, header);
        num++;
    }
    void push_back(T val) {
        if (num == 0)
            header = trailer = new node<T>(val);
        else 
            trailer = trailer->next = new node<T>(val);
        num++;
    }
    void pop_front () {
        node<T> *p = header;
        header = header->next;
        delete p;
        num--;
        if(num == 0)
            trailer = nullptr;
    }

    void pop_back () {
        if (num == 1)
            return pop_front();
        else {
            node<T> *p = header;
            while (p->next != trailer)
                p = p->next;
            delete trailer;
            trailer = p;
            p->next = nullptr;
            num--;
        }
    }

    typedef list_iterator<T> iterator;
    iterator begin () {return header;}
    iterator end () {return nullptr;}
    void insert(iterator it1, T x) {
        if (it1.cur ==  header)
            return push_front(x);
        if (it1.cur == nullptr)
            return push_back(x);
        it1.cur->next = new node<T>(*it1, it1.cur->next);
        it1.cur->data = x;
        num++;
        if (trailer->next)
            trailer = trailer->next; 
    }

    void erase(iterator &it1) {
        if (it1.cur == header)
            return pop_front();
        if (it1.cur == trailer)
            return pop_back();
        node<T> *p = header;
        while (p->next != it1.cur)
            p = p->next;
        p->next = it1.cur->next;
        delete it1.cur;
        num--;
    }

    void sort (bool tang = true) {
        for(node<T> *p=header;p!=NULL;p=p->next)
			for(node<T> *q=p->next;q!=NULL;q=q->next)
			if(p->elem>q->elem==tang) swap(p->elem,q->elem);
    }
};

#endif

int main () {
    linked_list<int> ls;
    for(int x:{0,65,2,623,764,2})
        ls.push_back(x);
    for(linked_list<int>::iterator it1 = ls.begin(); it1!=ls.end(); it1++)
        cout << *it1 << ' ';
}