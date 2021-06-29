
#include<iostream>
#include<windows.h>
#include"user.h"
#include"car.h"
using namespace std;

 void User::checkCar(){
    Car car;
    while(1){
        system("cls");
        cout<<"1.??????????"<<endl;
        cout<<"2.??????????"<<endl;
        cout<<"3.??????"<<endl;
        cout<<"4.?????????"<<endl;
        int ch;
        cout<<"?????????До??????";
        cin>>ch;
        switch(ch){
            case 1:car.showInfor();
                break;
            case 2:car.findCar();
                break;
            case 3:car.timeAmount();
                break;
            case 4:
                return ;
            default:
                cout<<"??????????????"<<endl;
        }
        system("pause");
    }
}
