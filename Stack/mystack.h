#pragma once 

#include <initializer_list>
#include <iostream>
// using namespace std;
const int MAX = 10;

class Stack{

    int top;
    int a[MAX];

public:
    Stack() : top(-1) {}
    Stack(std::initializer_list<int> l);

    bool push(int x);
    int pop();

    bool isEmpty() const;
    bool isFull() const;
    int peek() const;
    int getSize() const;
    int getElementByIndex(int i) const;


    const int capacity();
    void reserve(int n);
    void empty();

    friend std::ostream& operator<<(std::ostream &os, Stack &s);

};

