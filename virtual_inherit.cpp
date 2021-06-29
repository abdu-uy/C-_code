#include<iostream>
using namespace std;

class animal{
    public:
        virtual void speak()=0;
        virtual void eat()=0;
        virtual ~animal();
};

animal::~animal(){
    cout<<"animal 析构函数"<<endl;
}


class cat:public animal{
    public:
        void speak();
        void eat();
        ~cat();
};

void cat::speak(){
    cout<<"小猫要说话"<<endl;
}

void cat::eat(){
    cout<<"小猫要吃饭"<<endl;
}

cat::~cat(){
    cout<<"小猫的析构函数"<<endl;
}

class rabbit:public animal{
    public:
        void speak();
        void eat();
        ~rabbit();
};

void rabbit::speak(){
    cout<<"兔子再叫"<<endl;
}

void rabbit::eat(){
    cout<<"兔子要吃饭"<<endl;
}

rabbit::~rabbit(){
    cout<<"兔子的析构函数"<<endl;
}

int main(){
   // animal animal; animal 是抽象类（类内只有纯虚函数），抽象类不能有实例化对象，只为派生类提供函数接口
    animal* pc=new cat;
    pc->speak();
    pc->eat();

    animal* pr=new rabbit;
    pr->speak();
    pr->eat();
    delete pr;
    return 0;
}
