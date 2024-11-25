#include "mystack.h"
#include "mylist.h"

#include <iostream>

using namespace std;



int main(){

  List l = {10,20,40,30};
  cout<<l.size<<endl;
  // l.traverse();
  l.push_back(50); // 10,20,40,30,50
  // l.traverse();
  l.push_front(0); // 0,10,20,40,30,50
  // l.traverse();
  l.insert_at(4,30); // 0,10,20,30,40,30,50
  l.traverse();

  l.delete_at(1);
  l.traverse();



//     // cout<<"Test program to check stack implementation in array"<<endl;
//     Stack s = {5,10,15,20,25,30,35,40};
//     cout<<s;
//     cout<<"Capacity" << s.capacity() <<endl;
//     cout<<"Size: "<<s.getSize()<<endl;
//     cout<<s;
//     s.pop();
//     cout<<s;
//     s.push(33);
//     cout<<s;
// }

}