
#include "mydll.h"

using namespace std;

int main(){

  DLL dl = {1,20,30,4,5};
  dl.push_back(3);
  dl.push_front(4);
  dl.insert_at(33,6);
  cout<<dl;
  dl.pop_back();
  cout<<dl;
  dl.pop_front();
  cout<<dl;
  dl.pop_back();
  cout<<dl;
  // dl.delete_at(5);
  dl.clean();
  cout<<dl;

  // dl.printReverse();


  


}
