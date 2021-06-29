#include <iostream>
#include <string>
#include <exception>
using namespace std;


//首先，throw异常会一层一层往外抛出，最终会在最外层的catch里被抓到，
//throw语句后面的部分不会被执行
void func_inner(){
    throw "Unknown Exception";  //抛出异常
    cout<<"[1]This statement will not be executed."<<endl;
}

void func_outer(){
    func_inner();
    cout<<"[2]This statement will not be executed."<<endl;
}

int main(){
    try{
        func_outer();
        cout<<"[3]This statement will not be executed."<<endl;
    }catch(const char* &e){
        cout<<e<<endl;
    }

    return 0;
}