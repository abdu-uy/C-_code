#include<iostream>
#include<math.h>
using namespace std;
class complex
{
private:
    double m_real;
    double m_img;
   
public:
    complex();//无参数初始化用
    complex(double real,double img);//有参数初始化用
    complex(double real):m_real(real),m_img(0.0){}
    complex(double real=0,double img=0):m_real(real),m_img(img){}//这一个构造函数，实现以上三个构造函数的功能
    //定义全局的运算符重载
    friend complex operator+(const complex &a,const complex &b);
    friend complex operator-(const complex &a,const complex &b);
    friend complex operator*(const complex &a,const complex &b);
    friend complex operator/(const complex &a,const complex &b);
    friend bool operator==(const complex &a,const complex &b);
    friend bool operator!=(const complex &a,const complex &b);
    friend istream & operator>>(istream & in,complex &a);
    friend ostream & operator<<(ostream & out,complex &a);

    complex & operator+=(const complex &a);
    complex & operator-=(const complex &a);
    complex & operator*=(const complex &a);
    complex & operator/=(const complex &a);

    void display()const;//只读型修饰
};
    
complex::complex():m_real(0.0),m_img(0.0){}
complex::complex(double real,double img):m_real(real),m_img(img){}
void complex::display()const{
    cout<<m_real<<"+"<<m_img<<"i"<<endl;
}



//复数加
complex operator+(const complex &a,const complex &b);
complex operator+(const complex &a,const complex &b){//相加后返回复数类型
    complex c;
    c.m_real=b.m_real+a.m_real;
    c.m_img=b.m_img+a.m_img;
    return c;
}
//复数减
complex operator-(const complex &a,const complex &b);
complex operator-(const complex &a,const complex &b){//相加后返回复数类型
    complex c;
    c.m_real=b.m_real-a.m_real;
    c.m_img=b.m_img-a.m_img;
    return c;
}

//复数乘 (a+bi) * (c+di) = (ac-bd) + (bc+ad)i
 complex operator*(const complex &a,const complex &b);
 complex operator*(const complex &c1,const complex &c2){
    complex c;
    c.m_real = c1.m_real * c2.m_real - c1.m_img * c2.m_img;
    c.m_img = c1.m_img * c2.m_real + c1.m_real * c2.m_img;
    return c;
 }

//复数除 (a+bi) / (c+di) = [(ac+bd) / (c²+d²)] + [(bc-ad) / (c²+d²)]i
 complex operator/(const complex &a,const complex &b);
 complex operator/(const complex &c1,const complex &c2){
     complex c;
    c.m_real = (c1.m_real*c2.m_real + c1.m_img*c2.m_img) / (pow(c2.m_real, 2) + pow(c2.m_img, 2));
    c.m_img = (c1.m_img*c2.m_real - c1.m_real*c2.m_img) / (pow(c2.m_real, 2) + pow(c2.m_img, 2));
    return c;
 }

//复数相等
 bool operator==(const complex &c1, const complex &c2){
    if( c1.m_real == c2.m_real && c1.m_img == c2.m_img ){
        return true;
    }else{
        return false;
    }
}

//复数不等
bool operator!=(const complex &c1, const complex &c2){
    if( c1.m_real != c2.m_real || c1.m_img != c2.m_img ){
        return true;
    }else{
        return false;
    }
}

//复数自加
complex & complex::operator+=(const complex &a){
    this->m_real+=a.m_real;
    this->m_img+=a.m_img;
    return *this;
}

//复数自减
complex & complex::operator-=(const complex &a){
    this->m_real-=a.m_real;
    this->m_img-=a.m_img;
    return *this;
}

//重载*=运算符
complex & complex::operator*=(const complex &c){
    this->m_real = this->m_real * c.m_real - this->m_img * c.m_img;
    this->m_img = this->m_img * c.m_real + this->m_real * c.m_img;
    return *this;
}

//重载/=运算符
complex & complex::operator/=(const complex &c){
    this->m_real = (this->m_real*c.m_real + this->m_img*c.m_img) / (pow(c.m_real, 2) + pow(c.m_img, 2));
    this->m_img = (this->m_img*c.m_real - this->m_real*c.m_img) / (pow(c.m_real, 2) + pow(c.m_img, 2));
    return *this;
}

//输入重载
istream  & operator>>(istream & in,complex &a){
    in>>a.m_real>>a.m_img;
    return in;
}

//输出重载 
ostream & operator<<(ostream &out,complex &a){
    out<<a.m_real<<"+"<<a.m_img<<"i";
    return out;
}