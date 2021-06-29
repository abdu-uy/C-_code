#include<iostream>
using namespace std;


class  base1{
protected:
    int base1;
};

class base2{
protected:
    int base2;
};

class derive:public base1,public base2{
private:
    int derive;
};

class wood{
    public:
        wood(){cout<<"木材构造函数"<<endl;};
        ~wood(){cout<<"木材析构函数"<<endl;};
};

class sofa{
    public:
        sofa(){cout<<"沙发构造函数"<<endl;}
        ~sofa(){cout<<"沙发析构"<<endl;}
        void sit(){cout<<"沙发用来坐"<<endl;}

};

class bed{
    public:
        bed(){cout<<"床构造函数"<<endl;}
        ~bed(){cout<<"床析构函数"<<endl;}
        void sleep(){cout<<"bed用来睡觉"<<endl;}
};

class sofabed:public sofa,public bed{
    public:
        sofabed(){cout<<"沙发床构造函数"<<endl;}
        ~sofabed(){cout<<"沙发床析构函数"<<endl;}
        wood pearwood;
};


int main(){
    sofabed sbed;
    sbed.sit();
    sbed.sleep();
    return 0;
}


