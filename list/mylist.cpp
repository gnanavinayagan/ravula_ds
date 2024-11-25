

#include <iostream>
#include "mylist.h"

using namespace std;

List::List(): head{nullptr}, size{0} {}

List::List(std::initializer_list<int> i_list){
  head = nullptr;
  size = 0;
  for(auto &x: i_list){
    // cout<< "px/usu"<<endl;
    push_back(x);
  }
}

// Copy Constructor
List::List(const List& old_list){
  // cout<< "Shallow copy"<<endl;
  head = new node(old_list.head->data);
  size++;
  node* to_itr = head;
  node* from_itr = old_list.getHead();

  while(from_itr->link != nullptr){
    to_itr->link = new node(from_itr->link->data); 
    to_itr = to_itr->link;
    from_itr = from_itr->link;
    size++;
  }
}

// Move constructor
List::List(List&& old_list){
  head = old_list.getHead();
  size = old_list.getSize();
  old_list.setHead(nullptr);
}

// Copy Assignment 
List& List::operator=(List& old_list){
  if(this == &old_list){
    return *this;
  }
  
  head = new node(old_list.getHead()->data);
  size++;
  node* to_itr = head;
  node* from_itr = old_list.getHead(); 

  while(from_itr->link !=nullptr){
    to_itr->link = new node(from_itr->link->data);
    to_itr = to_itr->link;
    from_itr = from_itr->link;
    size++;
  }
  return *this;
}

// Move Assignment
List& List::operator=(List&& old_list){
  head = old_list.getHead();
  size = old_list.getSize();
  old_list.setHead(nullptr);
  return *this;
}

void List::setHead(node* headptr){
  head = headptr;
}
node* List::getHead() const{
  return head;
}

int List::getSize() const{
  return size;
}

bool List::isEmpty() const{
  return (head==nullptr);
}

bool List::isNonEmpty() const{
  return (head!= nullptr);
}

void List::traverse(){
  if(head == nullptr){
    cout<<"Nothing to print. List is empty"<< endl;
    return;
  }
  node* itr = head;
  while(itr!=nullptr){
    cout<<itr->data << " " << itr ;
    itr = itr->link;
  }
  cout<<endl;
}

// Adding element to list
void List::push_back(int data){
  node* newnode = new node(data);
  size++;
  if(head == nullptr){
    head = newnode;
    return;
  }
  node* itr = head;
  while (itr->link != nullptr){
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

void List::insert_at(int data, int pos){

  if(pos == 0 || pos > size){
    cout<<"Wrong position to insert"<<endl;
    return;
  }

  node* newnode = new node(data);
  size++;

  if(head == nullptr){
    head = newnode;
    return;
  }

  if(pos == 1){
    newnode->link = head;
    head = newnode;
    return;
  }

  node* itr = head;
  // if pos is very large, insert at last position
  for(int i=1; (itr->link != nullptr) && (i<pos-1); i++ ){
    itr=itr->link;
  }
  newnode->link = itr->link;
  itr->link = newnode;
}

// Deleting element from list
void List::delete_at(int pos){
  if(pos == 0 || pos>size){
    cout<<"Invalid position"<<endl;
    return;
  }

  if(head == nullptr){
    cout<<"Nothing to delete. Empty list"<< endl;
  }

  if(pos == 1){
    node* tmp = head;
    head = head->link;
    delete tmp;
    size--;
    return;
  }

  node* itr = head;
  for(int i=1; i<pos-1; i++){
    itr = itr->link;
  }
  node* tmp = itr->link;
  itr->link = itr->link->link;
  delete tmp;
  size--;

}

void List::pop_front(){
  if (head == nullptr){
    cout<<"Empty list"<<endl;
    return;
  }
  size--;
  node *tmp =  head;
  head = head->link;
  delete tmp;
}

void List::pop_back(){
  if (head == nullptr){
    cout<<"Empty list. Nothing to pop back";
    return;
  }
  size--;
  if(head->link == nullptr){
    delete head;
    head = nullptr;
    return;
  }
  node *itr = head;
  while(itr->link->link!=nullptr){
    itr = itr->link;
  }
  delete itr->link;
  itr->link = nullptr;
}

void List::clean(){
  node* tmp;
  while (head!=nullptr){
    tmp = head;
    head = head->link;
    delete tmp;
    size--;
  }
}

void List::reverse_print(){
  if (head == nullptr){
    cout<< "Empty list. Nothing to print"<< endl;
  }
  rec_print(head);
  cout << endl;
}


void List::rec_print(node* itr){
  if(itr!=nullptr){
    rec_print(itr->link);
    cout<<itr->data << " ";
  }
}

ostream& operator<<(ostream& os, List& list){

  node *itr = list.getHead();
  if (itr == nullptr){
    os << "List is empty. Nothing to print"<< endl;
    return os;
  }
  while(itr != nullptr){
    os << itr->data << " ";
    itr = itr->link;
  }
  os<<endl;
  return os;
}