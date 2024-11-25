

#include "mylist.h"


List::List(std::initializer_list<int> i_list){
  for(auto &x: i_list){
    push_back(x);
  }
}

node* List::getHead(){
  return head;
}

// printing list content 
void List::traverse(){
  if (head == nullptr){
    cout<< "Nothing to print. List is empty"<< endl;
    return;
  }
  node* itr = head;
  while(itr!= nullptr){
    cout<<itr->data << " ";
    itr = itr->link;
  }
  cout<<endl;
}

// Adding element to list
void List::push_back(int val){
  node* newnode = new node(val);
  size++;
  if(head == nullptr){
    head = newnode;
    return;
  }
  node *itr = head;
  while (itr->link != nullptr){
    itr = itr->link;
  }
  itr->link = newnode;
  
}

void List::push_front(int val){
  node* newnode = new node(val);
  newnode->link = head;
  head = newnode;
  size++;
}

void List::insert_at(int pos, int val){
  node* newnode = new node(val);
  if(head == nullptr){
    head = newnode;
    size++;
    return;
  }
  if(pos == 1){
    newnode->link = head;
    head = newnode;
  }
  node* itr = head;
  for (int i=1; (itr->link != nullptr) && (i < pos-1) ; i++){
    itr = itr->link;
  }
  newnode->link  = itr->link;
  itr->link = newnode;
  size++;
}


void List::delete_at(int pos){
  if(pos<=0 || pos >size){
    cout<<"Invalid position"<<endl;
    return;
  }

  if(head == nullptr){
    cout<< "Nothing to delete. Empty list" <<endl;
    return;
  }

  if(head->link == nullptr){ // && pos == 1
    size--;
    delete head;
    head = nullptr;
  }

  if (pos ==1){
    node* tmp = head;
    head = head->link;
    delete tmp;
    size--;
    return;
  }

  node* itr = head;
  for(int i=1;i<pos-1;i++){
    itr = itr->link;
  }
  node* tmp = itr->link;
  itr->link = itr->link->link;
  delete tmp;
  size--;
}

