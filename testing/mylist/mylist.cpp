#include <iostream>
#include "mylist.h"

using namespace std;


List::List(): head{nullptr}, size{0} {}

List::List(std::initializer_list<int> i_list){
  if(head == nullptr){
    cout<<"empty..........."<<endl;
  }
  // size = 0;
  print();
  clean();
  print();
  for(auto &x: i_list){
    cout<<size<<endl;
    push_back(x);    
  }
}

void List::clean(){
  cout<<"Cleaning list of size: "<<size<<endl;
  while(head != nullptr){
    node* tmp = head;
    head = head->link;
    delete tmp;
    size--;
    cout<<"current list size: "<<size<<endl;
  }
}


node* List::getHead() const{
  return head;
}

void List::setHead(node* headptr){
  head = headptr;
}

size_t List::getSize() const {
  return size;
}

bool List::isEmpty() const{
  return (head==nullptr);
}

bool List::isNonEmpty() const {
  return (head != nullptr);
}


void List::push_back(int data){
  node* newnode = new node(data);
  size++;
  if(head == nullptr){
    head = newnode;
    return;
  }
  node* itr = head;
  while(itr->link != nullptr){
    itr = itr->link;
  }
  itr->link = newnode;
}

void List::push_front(int data){
  node* newnode = new node(data);
  size++;
  newnode->link = head;
  head = newnode;
}

void List::insert_at(int pos, int data){ 
  
  // size n; position from 1 to n+1
  if(pos < 1 || pos > size+1) {
    cout<<"Invalid position to insert"<<endl;
  }
  
  node* newnode = new node(data);
  size++;

  node* itr = head;
  // go to pos-1 and insert at pos. move pos-2 times from 1 = pos-1
  for(int i=1; i < pos-1; i++){
    itr=itr->link;
  }
  newnode->link = itr->link;
  itr->link = newnode;

}


void List::print(){
  if(head == nullptr){
    cout<< "List is empty. Nothing to print";
  }
  node* itr = head;
  while(itr!=nullptr){
    cout<<itr->data << " ";
    itr=itr->link;
  }
  cout<<"\tSize: "<< size <<endl;
}