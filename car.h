#ifndef CAR_H
#define CAR_H

#include<string>
#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;

class Car{
public:
    void addCar();//???????
    void delCar();//???????
    void findCar();//???????
    void modCar();//????????
    void timeAmount();//??????
    void showInfor();//???????????????????
    void saveInfor();//???????????????????
private:
    string carNum;//???????
    string carType;//???
    string color;  //???
    time_t intTime; //??????
};

//增加车辆
void Car::addCar(){
    time_t _time;//定义时间变量
    while(1){
        AA:         cout<<"请输入车牌号 ";
            cin>>carNum;
            //判断车牌号是否重复
            ifstream ifs("carData.txt",ios::in);//读取文件

            if(ifs){//若文件读取成功，则判断车牌号是否重复
                char buf[1024];
                string strs[20];
                int index=0;

                while(!ifs.eof()){
                    ifs.getline(buf,100);//一行行读入数据

                    strs[index]=buf[0];//每次将第一个字段读入到str数组中
                    index++;
                }

                for(auto& num:strs){
                    if(num==carNum){
                        cout<<"车牌号重复!"<<endl;
                        goto AA;//跳转到车牌输入处
                    }
                }

            }
            cout<<"请输入车辆种类：";
            cin>>carType;
            cout<<"请输入车的颜色：";
            cin>>color;
            intTime =time(&_time);//记录停车时间
            saveInfor();
            char ch;

            cout<<"\t是否继续？(y/n)";
            cin>>ch;
            if(ch=='n'|| ch=='N')
                break;
    }
}

//删除车辆
void Car::delCar(){
    ifstream carData("carData.txt",ios::in);

    ofstream outData("tempcarData.txt",ios::out);
    if(!carData||!outData){
        cout<<"文件打开失败!"<<endl;
        return ;
    }
    string carlisence,name,str;
    bool flag=true;
    cout<<"请输入要删除的车牌号：";
    cin>>carlisence;
    //将cardata的第一个字段读入到name里，>>遇到空格就停止读入
    while(carData>>name){
        getline(carData,str);
        if(carlisence==name){
            cout<<"要删除的车辆信息："<<endl<<str<<endl;
            flag=false;
            break;
        }
        //若车牌号不相等，将信息写入到tempcarData.txt文件中
        outData<<name<<" "<<str<<endl;
    }
    if(flag){
        cout<<"该车牌号不存在"<<endl;
    }
    else{
        while(getline(carData,str)){
            outData<<str<<endl;
        }
        carData.close();
        outData.close();
        //下面再将tempcardata里的数据再次写入到cardata里面去
        ifstream in("tempcarData.txt",ios::in);
        ofstream out("carData.txt",ios::out);

        if(!in||!out){
            cout<<"文件打开失败！"<<endl;
            return ;
        }
        else
            while(getline(in,str)){
                out<<str<<endl;
            }
        
            in.close();
            out.close();
    }
}

//查找车辆

void Car::findCar(){
    ifstream carData("carData.txt",ios::in);
    if(!carData){
        cout<<"打开文件失败！"<<endl;
    }
    else{
        string carlisence;
        time_t _time,t1;
        bool flag=true;
        cout<<"请输入要查询的车牌号：";
        cin>>carlisence;
        while(carData>>carNum){
            carData>>carType>>color>>intTime;
            t1=time(&_time);

            if(carlisence==carNum){
                flag=false;
                break;
            }
        }
        if(flag)
            cout<<"未查询到该车辆信息!"<<endl;
        else{
            cout<<"车牌号："<<carNum<<" "<<"车辆类型："<<carType<<" "<<"颜色："<<color<<" "
            <<"停车时长："<<(t1-intTime)<<"秒"
            <<" "<<"计费："<<(t1-intTime)*0.005<<"元"<<endl;
        }
    }
    carData.close();
}

//修改车辆信息
void Car::modCar(){

    ifstream carData("carData.txt",ios::in);
    ofstream outData("tempcarData.txt",ios::out);
    if(!carData||!outData){
        cout<<"文件打开失败!"<<endl;
        return ;
    }
    string name,str;
    bool flag=true;
    cout<<"请输入要修改的车牌号：";
    cin>>carNum;
    //将cardata的第一个字段读入到name里，>>遇到空格就停止读入
    while(carData>>name){
        getline(carData,str);
        if(carNum==name){
            time_t _time;
            cout<<"修改后的车牌号：";
            cin>>carNum;
            cout<<"修改后的车的种类";
            cin>>carType;
            cout<<"修改后的车的颜色";
            cin>>color;
            intTime =time(&_time);

            outData<<carNum<<" "<<carType<<" "<<color<<" "<<intTime<<endl;
            flag=false;
            break;
        }

        //若车牌号不相等，将信息写入到tempcarData.txt文件中
        outData<<name<<" "<<str<<endl;
    }
    if(flag){
        cout<<"修改车辆信息不存在！"<<endl;
    }
    else{
        while(getline(carData,str)){
            outData<<str<<endl;
        }
        carData.close();
        outData.close();
        //下面再将tempcardata里的数据再次写入到cardata里面去
        ifstream in("tempcarData.txt",ios::in);
        ofstream out("carData.txt",ios::out);

        if(!in||!out){
            cout<<"文件打开失败！"<<endl;
            return ;
        }
        else
            while(getline(in,str)){
                out<<str<<endl;
            }
        
            in.close();
            out.close();
    }
}

//显示所有车辆信息
void Car::showInfor(){
    ifstream carData("carData.txt",ios::in);
    if(!carData){
        cout<<"打开文件失败！"<<endl;
        return ;
    }
    else
    {
        bool flag=true;
        time_t _time,t;
        while(carData>>carNum){
            carData>>carType>>color>>intTime;
            t=time(&_time);
            cout<<"车牌号："<<carNum<<" "<<"车辆类型："<<carType<<" "<<"颜色："<<color<<" "
            <<"停车时长："<<(t-intTime)<<"秒"
            <<" "<<"计费："<<(t-intTime)*0.005<<"元"<<endl;
            flag=false;
        }
        if(flag){
            cout<<"\n无车辆信息"<<endl;
        }
        else{
            cout<<"\n车辆信息已显示"<<endl;
        }
       
    }
     carData.close();
}


//计算停车时长
void Car::timeAmount(){
    ifstream carData("carData.txt",ios::in);
    if(!carData){
        cout<<"打开文件失败！"<<endl;
        return ;
    }  
    else{
        int c1=0,c2=0;//c1:车辆总数，c2:不超过一天的车辆总数
        time_t _time,t1;
        while(carData>>carNum){
            c1++;
            t1=time(&_time);
            carData>>carType>>color>>intTime;
            if((t1-intTime)*0.0001<long(8.64))
                c2++;
        }
        cout<<"车辆总数："<<c1<<endl;
        cout<<"停车时间不超过一天："<<c2<<endl;
        cout<<"停车时间超过一天："<<c1-c2<<endl;
    }  
    carData.close();
}

//保存车辆信息
void Car::saveInfor(){
    ofstream outData("carData.txt",ios::app);
    if(!outData){
        cout<<"打开文件失败！"<<endl;
        return ;
    }
    else{
        outData<<carNum<<" "<<carType<<" "<<color<<" "<<intTime<<endl;
    }
    outData.close();
}


#endif