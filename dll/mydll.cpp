#include "mydll.h"

#define mt() { std::cout<<"Nothing to print. DLL is empty."<<endl; }
using namespace std;


DLL::DLL(): head{nullptr}, size{0} {}

DLL::DLL(std::initializer_list<int> dll_list): head{nullptr}, size{0}{
  for(auto& x: dll_list){
    // cout<<x <<" ";
    push_back(x);
  }
  cout<<endl;
}

// utility functions

dnode* DLL::getHead() const{
  return head;
}
size_t DLL::getSize() const{
  return size;
}

bool DLL::isEmpty() const {
  return head == nullptr;
}

bool DLL::isNonEmpty() const {
  return head != nullptr;
}

// insertion
void DLL::push_front(int val){
  dnode* newnode = new dnode(val);
  size++;

  if (head == nullptr) {
    head = newnode;
    return;
  }
  newnode->next = head;
  head->prev = newnode;
  head = newnode;
}

void DLL::push_back(int val){
  dnode* newnode = new dnode(val);
  size++;
  if(head == nullptr){
      head = newnode;
      return;
  }
  dnode* itr = head;
  while (itr->next != nullptr){
    itr = itr->next;
  }
  itr->next = newnode;
  newnode->prev = itr;
}

void DLL::insert_at(int val, int pos){
  

  if(pos == 0 || pos > size){
    cout<<"Wrong position to insert"<<endl;
    return;
  }

  dnode* newnode = new dnode(val);
  size++;

  if(head == nullptr){
    head = newnode;
    return;
  }

  if (pos == 1){
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
    return;
  }

  dnode* itr = head;
  for(int i=1;(i<pos-1 && itr!=nullptr); i++){
    itr = itr->next;
  }

  dnode* tmp = itr->next;
  newnode->next = itr->next;
  newnode->prev = itr;
  itr->next->prev = newnode;
  itr->next = newnode;

}

// deletion 
void DLL::pop_back(){
  if (head == nullptr){
    cout<< "Nothing to delete"<<endl;
  }
  dnode* itr = head;
  while(itr->next != nullptr){
    itr = itr->next;
  }
  itr->prev->next = nullptr; // itr pointing last element
  delete itr;

}

void DLL::pop_front(){
  if (head == nullptr){
    cout<<"Nothing to delete. DLL is empty";
  }
  dnode* tmp = head;
  head = head->next;
  head->prev = nullptr;
  delete tmp;
}

void DLL::delete_at(int pos){
  if(head == nullptr){
    cout<<"Nothing to delete. DLL is empty"<<endl;
    return;
  }
  if(pos <=0 or pos > size ){
    cout<<"Wrong position to delete";
    return;
  }
  if(pos == 1){
    dnode* tmp = head;
    head = head->next;
    head->prev = nullptr;
    delete tmp;
    return;
  }
  dnode* itr = head;
  for(int i=1; i<pos-1; i++){
    itr = itr->next;
  }
  // itr = pos-1
  dnode *tmp = itr->next;
  itr->next = itr->next->next;
  if(itr->next!=nullptr){
    itr->next->prev = itr;
  }
  delete tmp;
}

void DLL::clean(){
  if (head == nullptr){
    cout<<"Already clean. Nothing to delete";
  }
  dnode* itr = head;
  while (itr != nullptr){
    dnode* tmp = itr;
    itr = itr->next;
    delete tmp;
    size--;
  }
  head = nullptr;

}



// print
void DLL::printReverse(){
  if (head ==nullptr){
    mt();
  }
  dnode* itr = head;
  while(itr->next!= nullptr){
    itr = itr->next;
  }
  while (itr!=nullptr){;
    cout<<itr->data<<" ";
    itr = itr->prev;
  }
  cout<<endl;
}

void DLL::print(){
  if(head == nullptr){
    mt();
  }
  dnode* itr = head;
  while(itr != nullptr){
    cout<<itr->data << " ";
    itr = itr->next;
  }
  cout<<endl;
}


ostream& operator<<(ostream& os, DLL& dl){

  if (dl.getHead() == nullptr){
    mt();
  }
  dnode* itr = dl.getHead();
  while (itr != nullptr){
    os<<itr->data<<" ";
    itr = itr->next;
  }
  os<<endl;
  return os;
}