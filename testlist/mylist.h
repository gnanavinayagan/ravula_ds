#pragma once
#include "config.h"
#include <initializer_list>
#include <iostream>

class List{
  public:
    node* head;
    size_t size;

  public:
    List();
    List(std::initializer_list<int> i_list);

    // must 5
    List(const List& old_list);
    List(List&& old_list);
    List& operator=(List& old_list);
    List& operator=(List&& old_list);

    node* getHead() const;
    void setHead(node* headptr);
    int getSize() const;

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


    // recursive function
    void reverse_print();
    void rec_print(node* itr);
    
    friend std::ostream& operator<<(std::ostream& os, List& l);

};
