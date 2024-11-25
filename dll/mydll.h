#pragma once
#include "config.h"
#include <initializer_list>
#include <iostream>
using namespace std;

class DLL{
  public:
    dnode* head;
    size_t size;

  public:
    DLL();
    DLL(std::initializer_list<int> dll_list);

    dnode* getHead() const;
    size_t getSize() const;
    void setHead(dnode* headptr);

    bool isEmpty() const;
    bool isNonEmpty() const;

    // insertion
    void push_back(int data);
    void push_front(int data);
    void insert_at(int val, int pos);

    // deletion
    void delete_at(int pos);
    void pop_back();
    void pop_front();
    void clean();

    void print();
    void printReverse();
    

  friend std::ostream& operator<<(std::ostream& os, DLL& dl);

};
