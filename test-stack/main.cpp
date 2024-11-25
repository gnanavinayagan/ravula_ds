
#include "mystack.h"

using namespace std;
int main(){

  // Stack s;



  // cout<<"Test program to check stack implementation in array"<<endl;
  Stack s = {5,10,15,20,25,30,35,40};
  cout<<s;
  cout<<"Capacity" << s.capacity() <<endl;
  cout<<"Size: "<<s.getSize()<<endl;
  cout<<s;
  s.pop();
  cout<<s;
  s.push(33);
  cout<<s;


}

