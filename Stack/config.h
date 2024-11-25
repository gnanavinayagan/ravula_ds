#pragma once
#include <iostream>
#include <initializer_list>

struct node{
  int data;
  struct node* link; // pointer to next node

  node(): data{0}, link{nullptr} {}
  node(int val): data{val}, link{nullptr} {}
};