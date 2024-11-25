
#include "mylist.h"

using namespace std;

int main(){

  cout<<"sample program to test"<<endl;


  List l = {10,20,30,40};
  List l1 = l;
  
  l.insert_at(50,5);
  l.traverse();
  
  l1.traverse();
  // cout<<l1.head->link<<endl;
  cout<<l.getSize()<<endl;
  cout<<l1.getSize()<<endl;

  // List l2(l);
  // l2.traverse();
  // cout<<l.head<<endl;
  // cout<<l2.head<<endl;

}
