#include <iostream>
#include <iomanip>
using namespace std;

int main () {
  double pi=3.1415926;
  cout<<setprecision(2)<<pi<<endl;
  cout<<fixed<<setprecision(2)<<pi<<endl;
  cout<<setw(10)<<setfill('#')<<fixed<<setprecision(2)<<left<<pi;
  
   return 0;
}