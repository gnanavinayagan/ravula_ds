#include "mydll.h"
using namespace std;

#define mt() { std::cout<<"Nothing to print. DLL is empty."<<endl; }


DLL::DLL(): head{nullptr}, size{0} {}

DLL::DLL(std::initializer_list<int> dll_list): head{nullptr}, size{0}{
  for(auto& x: dll_list){
    push_back(x);
  }
}

dnode* DLL::getHead() {
  return head;
}

size_t DLL:: getSize(){
  return size;
}

bool DLL::isEmpty(){
  return head == nullptr;
}

bool DLL::isNonEmpty(){
  return head != nullptr;
}


void DLL::push_back(int val){
  dnode* newnode = new dnode(val);
  size++;

  if(head == nullptr){
    head = newnode;
    return;
  }

  dnode* itr = head;
  // itr->next == nullptr -> last node
  // itr == nullptr -> after last node
  while(itr->next!=nullptr){  
    itr = itr->next;
  }

  // itr pointing tolast 
  itr->next = newnode;
  newnode->prev = itr;
}

void DLL::push_front(int data){
  
  dnode* newnode = new dnode(data);
  size++;
  if(head == nullptr){
    head = newnode;
    return;
  }

  newnode->next = head;
  head->prev = newnode;
  head = newnode;

}

void DLL::insert_at(int val, int pos){
  // 1 to size+1
  // if (head == nullptr)
  if (pos == 0 || pos > size+1){
    cout<<"wrong position to insert"<<endl;
    return;
  }

  dnode* newnode = new dnode(val);
  size++;

  if(pos == 1){

    if (head == nullptr){
      head = newnode;
      return;
    }

    newnode->next = head;
    head->prev = newnode; // to avoid this step
    head = newnode;
    return;
  }


  dnode* itr = head;
  for(int i=1; (i<pos-1 && itr!= nullptr) ; i++ ){   // i==pos-1
    itr = itr->next;
  }

  dnode* tmp = itr->next;
  newnode->next = itr->next;
  newnode->prev = itr;
  if (newnode->next != nullptr){
    newnode->next->prev = newnode;
  }

  itr->next = newnode;


}


void DLL::pop_back(){
  if (head == nullptr){
    cout<<"Nothing to delete. dll is empty"<< endl;
    return;
  }
  dnode* itr = head;
  while(itr->next != nullptr){
    itr = itr->next;
  }
  itr->prev->next = nullptr;
  delete itr;
  size--;

}

void DLL::pop_front(){
  
  if(head == nullptr){
    cout<<"Nothing to delete. dll is empty"<< endl;  
  }

  dnode* tmp = head;
  head = head->next;
  head->prev = nullptr;
  delete tmp;
  size--;

}

void DLL::delete_at(int pos){

  if(head == nullptr){
    cout<<"Nothing to delete. dll is empty"<< endl;
    return;
  }
  if(pos==0 or pos>size){
    cout<<"Wrong pos to delete"<< endl;
    return;
  }

  if(pos == 1){
    dnode* tmp = head;
    head = head->next;
    if (head != nullptr)
      head->prev = nullptr;
    delete tmp;
    size--;
    return;
  }
  dnode* itr = head;
  for(int i=1; i<pos-1; i++){
    itr = itr->next;
  }
  // i = pos-1

  dnode* tmp = itr->next;
  if(tmp->next != nullptr)
    tmp->next->prev = itr;
  itr-> next = tmp->next;
  
  delete tmp;
  size--;
}

void DLL::clean(){
  if (head == nullptr){
    cout<<"Nothing to clean. DLL is aready clean"<< endl;
    return;
  }
  dnode* itr = head;
  while(itr != nullptr){
    dnode* tmp = itr;
    itr = itr->next;
    delete tmp;
    size--;
  }
  head = nullptr;
}


void DLL::rev(dnode* node){
  if (node == nullptr){
    return;
  }
  else{
    rev(node->next);
    cout<<node->data<< " ";
  }
}

void DLL::fro(dnode* node){
  if (node == nullptr){
    return;
  }
  else{
    cout<<node->data<< " ";
    fro(node->next);
  }
}


void DLL::printFroRec(){
  fro(head);
  cout<< endl;
}

void DLL::printRevRec(){
  rev(head);
  cout<< endl;
}


void DLL::printReverse(){
  if(head == nullptr)
    mt();

  dnode* itr = head;
  while(itr->next != nullptr)
    itr = itr->next;
  while(itr != nullptr){
    cout<<itr->data<<" ";
    itr = itr->prev;
  }
  cout<<endl;
}


void DLL::print(){
  
  if(head == nullptr){
    cout<<"Nothing to print"<<endl;
  }

  dnode* itr = head;
  while(itr!= nullptr){
    cout<< itr->data << " ";
    itr = itr->next;
  }
  cout<<endl;
}

ostream& operator<<(ostream& os, DLL& dl){

  if(dl.isEmpty()){
    mt();
    return os;
  }
  dnode* itr = dl.getHead();
  while(itr != nullptr){
    os<< itr->data<< " ";
    itr = itr->next;
  }
  os<<" Size: "<< dl.getSize() <<  endl;
  return os;
}

