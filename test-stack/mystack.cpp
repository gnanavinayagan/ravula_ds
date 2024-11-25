#include "mystack.h"

using namespace std;

#define mt() {cout <<"Stack is empty"<< endl; return true;}
#define fl() {cout <<"Stack is full" << endl; return true; }

Stack::Stack(std::initializer_list<int> ilist){
  top = -1;
  for(auto& x: ilist){
    if(!push(x)){
      cout<< "Cannot insert "<< x << endl;
    }
  }
}


bool Stack::push(int data){
  if(isFull())
    return false;
  a[++top] = data;
  return true;
}

int Stack::pop(){
  if(isEmpty())
    return -1;
  return a[top--];
}

void Stack::empty(){
  top = -1;
}

int Stack::peek() const{
  if(!isEmpty())
    return a[top];
  return -1;
}

int Stack::getSize() const{
  return top+1;
}

int Stack::getElementByIndex(int i) const{
  if(i>=0 && i<top){
    return a[i];
  }
  return -1;
}

const int Stack::capacity(){
  return MAX;
}


void Stack::reserve(int x){
  cout<<"Nothing to do";
} 

bool Stack::isFull() const{
  if(top+1>MAX){
    fl();
    return true;
  }
  return false;
}

bool Stack::isEmpty() const{
  if(top <= -1){
    mt();
    return true;
  }
  return false;
}


std::ostream& operator<<(ostream& os, Stack& s){
  for(int i=0;i<s.getSize(); i++){
    os<< s.getElementByIndex(i) << " ";
  }
  os<< endl;
  return os;
}