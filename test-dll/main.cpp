
#include "mydll.h"

using namespace std;

int main(){


  DLL dl;

  cout<<dl;
  dl = {1,2,3,4,5,67,8,9};
  // dl.pop_back();
  // dl.push_back(5);
  // dl.push_back(6);
  // dl.push_back(7);
  // dl.push_back(8);
  // dl.push_front(4);
  // dl.push_front(3);
  // dl.push_front(2);
  // dl.insert_at(1,1);
  // dl.insert_at(9,9);
  // cout<<dl;
  // dl.printReverse();

  
  cout<<"popback  -----------------"<<endl;
  dl.pop_back();
  cout<<dl;
  dl.pop_front();
  cout<<dl;
  dl.printRevRec();
  dl.printFroRec();

  cout<< "delete at --------------"<< endl;
  dl.delete_at(0);
  cout<<dl;
  dl.delete_at(1);
  cout<<dl;
  dl.delete_at(3);
  cout<<dl;
  dl.delete_at(5);
  cout<<dl;
  dl.delete_at(5);
  cout<<dl;

  cout<<"print reverse ---------------"<<endl;
  dl.printReverse();
  
  


  cout<< "claen--------------"<<endl;
  cout<<dl;
  dl.clean();
  dl.clean();
  cout<<dl;
}

