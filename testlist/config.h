#pragma once
#include <iostream>
#include <initializer_list>

struct node{
  
  int data;
  struct node* link;

  node(int val): data{val}, link{nullptr} {}
  node(): data{0}, link{nullptr}{}

};