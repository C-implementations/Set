//
// Created by DanielMolnar on 2024-04-05.
//

#ifndef SET_SET_H
#define SET_SET_H

#include <iostream>

class Set
{
private:
    int *elements;
    int count;
    friend std::ostream& operator <<(std::ostream &os, Set &s);
    friend Set& operator+(const Set &a, const Set &b);
    friend Set& operator+(const Set& a, const int element);
    friend Set& operator+(const int element, const Set &a);
    friend int operator<(const int e, const Set &a);
    friend int operator<=(const Set &a, const Set &b);
    friend int operator>=(const Set &a, const Set &b);
    friend Set& operator*(const Set &a, const Set &b);
    void setSorter();

public:
    Set();
    explicit Set(int n=0, int *e= nullptr);
    ~Set();
    Set& operator =(const Set &s);
    Set& operator =(int i);
    Set& operator+=(const Set &s);
    int operator==(const Set &s);
    int operator!=(const Set &s);
};

#endif //SET_SET_H
