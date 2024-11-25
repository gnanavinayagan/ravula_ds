#include "mystack.h"

using namespace std;

// constexpr bool mt() { cout << "Stack is empty" << endl; return true;}
// constexpr book fl() { cout << "Stack Overflow" << endl; return true;}

Stack::Stack(std::initializer_list<int> l){
    top = -1;
    for(auto& x : l){
        if(!push(x))
        {
            cout<< "Cannot insert "<< x <<endl;
        }
    }
}

bool Stack::push(int x){
    if(!isFull()){
        // cout<<"Pushing"<<endl;
        a[++top] = x;
        return true;
    }
    return false;
}

int Stack::pop(){
    cout<<"Popping"<<endl;
    if(!isEmpty()){
        return a[top--];
    }
    return -1;
}

void Stack::empty(){
    top = -1;
}

bool Stack::isEmpty() const {
    if(top<=-1){
        cout<< "\nStack is empty";
        return true;
    }
    return false;
}

bool Stack::isFull() const {
    if(top+1>=MAX){
        cout<< "Stack Overflow"<<endl;
        return true;
    }
    return false;
}

int Stack::peek() const {
    if(!isEmpty()){
        return a[top];
    }
    return -1;
}

int Stack::getSize() const {
    return top+1;
}

int Stack::getElementByIndex(int i) const{
    if ( (i>=0) && (i<=top) ) {
        return a[i];
    }
    return -1;
}

const int Stack::capacity(){
    return MAX;
}


void Stack::reserve(int x){
    cout<<"\nNothing to do";
}

std::ostream& operator<<(std::ostream& os, Stack& s){
    
    for(int i=0;i<s.getSize();i++){
        os << s.getElementByIndex(i) << " ";
    }
    os<<endl;
    return os;
}




