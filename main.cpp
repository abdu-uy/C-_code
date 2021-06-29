#include"admin.h"
#include<windows.h>
#include<iostream>
using namespace std;

int main(){
    User user;
   
        char ch;
        
        while (1)
        {
            system("cls");
            cout<<"1.普通用户登录"<<endl;
            cout<<"2.管理员登陆"<<endl;
            cout<<"3.退出系统"<<endl;
            cout<<"请输入所要进行的操作:"<<endl;
            cin>>ch;
            switch (ch)
            {
            case '1':user.checkCar();
                    break;
            case '2':Admin();
                    break;
            case '3':exit(0);               
            
            default:
                cout<<"输入有误，请重新输入:"<<endl;
            }
        }
        return 0;
        
}
