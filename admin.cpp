
#include"admin.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
 
  Admin::Admin(){
    Car car;
    while(1){
        system("cls");
        cout<<"1.���ӳ���"<<endl;
        cout<<"2.��ʾ���г�����Ϣ"<<endl;
        cout<<"3.��ѯ"<<endl;
        cout<<"4.�޸�"<<endl;
        cout<<"5.ɾ��"<<endl;
        cout<<"6.ͳ��"<<endl;
        cout<<"7.�˳������û�"<<endl;
        int i;
        cout<<"������Ҫִ�еĲ�����";
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
                cout<<"�������"<<endl;
        }
        system("pause");
    }
}
