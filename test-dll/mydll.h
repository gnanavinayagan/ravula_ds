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
    DLL();;
    DLL(std::initializer_list<int> dll_list);

    dnode* getHead();
    bool isEmpty();
    bool isNonEmpty();
    size_t getSize();


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
    void printRevRec();
    void rev(dnode* node);
    void printFroRec();
    void fro(dnode* node);

  friend std::ostream& operator<<(std::ostream& os, DLL& dl);

};
