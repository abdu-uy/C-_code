#include<iostream>
using namespace std;

class complex
{
private:
    double m_real;
    double m_img;
   
public:
    complex();//无参数初始化用
    complex(double real,double img);//有参数初始化用

    complex operator+(const complex &a)const;//用const修饰表示，传进去的变量是只读的
    void display()const;//只读型修饰
};
    
complex::complex():m_real(0.0),m_img(0.0){}
complex::complex(double real,double img):m_real(real),m_img(img){}
void complex::display()const{
    cout<<m_real<<"+"<<m_img<<"i"<<endl;
}
complex complex::operator+(const complex &a)const{//相加后返回复数类型
    complex b;
    b.m_real=this->m_real+a.m_real;
    b.m_img=this->m_img+a.m_img;
    return b;
}

int main(){
    complex c1(2.0,3.0);
    complex c2(3.0,3.4);
    complex c3;
    c1.display();
    c2.display();
    c3=c3.operator+(c1);
    c2=c2.operator+(c1);
    c3.display();
    c2.display();
    return 0;
}
