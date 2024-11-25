#pragma once
#include "config.h"
#include <initializer_list>


class List{
  public:
    node* head;
    size_t size;

  public:
    List();
    List(std::initializer_list<int> i_list);

    node* getHead() const;
    void setHead(node* nodeptr);
    size_t getSize() const;

    bool isEmpty() const;
    bool isNonEmpty() const;


    // insertion
    void push_back(int val);
    void push_front(int val);
    void insert_at(int pos, int val);

    // deletion
    void delete_at(int pos);
    void pop_back();
    void pop_front();
    void clean();

    // traversal
    void traverse();

    // print  
    void print();
    void printReverse();
    void printRec();
    void printReverseRec();


  friend std::ostream& operator<<(std::ostream& os, List &list);

};