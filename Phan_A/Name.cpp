#include<bits/stdc++.h>
using namespace std;

#ifndef FullName_h
#define FullName_h

class FullName{
private:
    string ho, ten;
public:
    friend istream &operator>> (istream &is, FullName &fn){
        string str;
        getline(is, str);;
        fn.ho = str.substr(0, str.find_last_of(" "));
        fn.ten = str.substr(str.find_last_of(" ") + 1);
        return is;
    }

    friend ostream &operator<< (ostream &os, FullName fn){
        string str = fn.ho + " " + fn.ten;
        cout << str;
        return os;
    }

    FullName operator=(FullName fullName){
        ho = fullName.ho;
        ten = fullName.ten;
        return *this;
    }
    string getHo(){
        return ho;
    }
    string getTen(){
        return ten;
    }
    bool operator<(FullName fullName){return ten < fullName.ten || (ten == fullName.ten && ho < fullName.ho);}
    bool operator>(FullName fullName){return ten > fullName.ten || (ten == fullName.ten && ho > fullName.ho);}
    bool operator==(FullName fullName){return ten == fullName.ten && ho == fullName.ho;}
    bool operator!=(FullName fullName){return !(*this == fullName);}
    bool operator<=(FullName fullName){return *this < fullName || *this == fullName;}
    bool operator>=(FullName fullName){return *this > fullName || *this == fullName;}
};

#endif