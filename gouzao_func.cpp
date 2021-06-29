#include <iostream>
#include <string>
using namespace std;

void func(string str){
    cout<<str<<endl;
}

int main(){
    string s1 = "http://c.biancheng.net";
    string s2(s1);
    string s3 = s1;
    string s4 = s1 + " " + s2;
    func(s1);
    cout<<s1<<endl<<s2<<endl<<s3<<endl<<s4<<endl;
   
    return 0;
}