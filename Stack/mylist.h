#pragma once
#include "config.h"
#include <initializer_list>
#include <iostream>
using namespace std;

class List{
  public:
    node* head;
    size_t size;

  public:
    List();
    // List(node* i_node);
    // // must 5
    // List(Const List& old_list); // copy constructor
    // List& operator=(const List& old_list); // copy assignment 
    // List(List&& old_list); // move constructor
    // List& operator=(List&& old_list);
    // ~List();

    List(std::initializer_list<int> i_list);
    
    node* getHead();
    
    // insertion 
    void push_back(int val);
    void push_front(int val);
    void insert_at(int pos, int val);

    // deletion
    void delete_at(int pos);


    void traverse();
    // void traverse(  );  


};