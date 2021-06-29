#ifndef USER_H
#define USER_H


#include<string>
#include<iostream>
#include"car.h"
using namespace std;

class User{
public:
    void checkCar();//?????????????????
};

void User::checkCar(){
    Car car;
    while(1){
        system("cls");
        cout<<"1.显示车辆信息"<<endl;
        cout<<"2.查找车辆"<<endl;
        cout<<"3.计时"<<endl;
        cout<<"4.退出"<<endl;
        int ch;
        cout<<"请选择操作：";
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
                cout<<"输入有误请重新输入:"<<endl;
        }
        system("pause");
    }
}


#endif