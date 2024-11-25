
#include "mylist.h"

using namespace std;

int main(){

  cout<<"sample program to test"<<endl;

  List l = {10,20,30,40};
  l.print();
  cout<<"\n\nDoing for second time......"<<endl;

  l = {1,2,3,4};
  l.print();

  // List l;
  // l.push_back(5);
  // l.push_back(4);
  // l.push_back(3);
  // l.push_back(2);
  // l.push_front(6);
  // l.push_front(7);
  // l.push_front(8);
  // l.push_front(9);
  // l.print();

  // List l = {10,20,30,40};
  // List l1 = l;
  
  // l.insert_at(50,5);
  // l.traverse();
  
  // l1.traverse();
  // // cout<<l1.head->link<<endl;
  // cout<<l.getSize()<<endl;
  // cout<<l1.getSize()<<endl;

  // // List l2(l);
  // // l2.traverse();
  // // cout<<l.head<<endl;
  // // cout<<l2.head<<endl;

}
