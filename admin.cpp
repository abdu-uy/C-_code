
#include"admin.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
 
  Admin::Admin(){
    Car car;
    while(1){
        system("cls");
        cout<<"1.增加车辆"<<endl;
        cout<<"2.显示所有车辆信息"<<endl;
        cout<<"3.查询"<<endl;
        cout<<"4.修改"<<endl;
        cout<<"5.删除"<<endl;
        cout<<"6.统计"<<endl;
        cout<<"7.退出管理用户"<<endl;
        int i;
        cout<<"请输入要执行的操作：";
        cin>>i;

        switch(i){
            case 1:car.addCar();
                break;
            case 2:car.showInfor();
                break;
            case 3:car.findCar();
                break;
            case 4:car.modCar();
                break;
            case 5:car.delCar();
                break;
            case 6:car.timeAmount();
                break;
            case 7:
                return ;
            default:
                cout<<"输入错误！"<<endl;
        }
        system("pause");
    }
}
