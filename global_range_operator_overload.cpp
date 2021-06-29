#include<iostream>
#include"complex.h"
using namespace std;


int main(){
    complex c1,c2,c3,c4;
    cin>>c1>>c2;
    cout<<c1<<c2;
    c3=c1+c2;
    cout<<c3<<endl;
    c4=(2.0,4.3);//使用了运算符重载，使得当只赋值一个整数时，虚部自动定义成零。
    c4=9.2;
    cout<<c4<<endl;
    return 0;
}
