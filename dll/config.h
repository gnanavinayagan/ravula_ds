#pragma once
#include <iostream>
#include <initializer_list>

struct node{
  int data;
  struct node* link;
  node(int val): data{val}, link{nullptr} {}
  node(): data{0}, link{nullptr}{}
};

struct dnode{
  int data;
  dnode* prev;
  dnode* next;
  dnode(int val): data{val}, prev{nullptr}, next{nullptr}{}
  dnode(): data{0}, prev{nullptr}, next{nullptr}{}
};