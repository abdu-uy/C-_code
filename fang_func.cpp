#include<iostream>
#include<string>
using namespace std;

class show{
public:
    void operator()(const string str){
        cout<<str<<endl;
    }
    float operator()(const float num){
        return num*num;
    }
};
//we juast overload the operator"()" inner class,it does not mean constructor anymore
int main(){
    show s;
    s("abdusaimi ");
    cout<<s(9.4)<<endl;
    return 0;
}