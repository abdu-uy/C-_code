#include<iostream>
#include<string>
using namespace std;

class student{
public:
    //两种构造方式，实例化的时候用哪个都行
    student(string name="",int age=0,float score=0.0f);//传参构造函数
    student(const student  &stu);//拷贝构造函数
public:
    void display();
private:
    string m_name;//为了便于进行赋值和复制，使用string类型
    int m_age;
    float m_score;
};

//传参型构造函数的定义
student::student(string name,int age,float score):
m_name(name),m_age(age),m_score(score){}

//拷贝型构造函数的定义，因为此时只用到stu的值，
//不对其本身进行修改，因此应使用const来修饰
student::student(const student &stu){
    this->m_name=stu.m_name;
    this->m_age=stu.m_age;
    this->m_score=stu.m_score;
    cout<<"constructor called!"<<endl;
}

void student::display(){
    //用公有函数访问私有成员，此时不宜使用this指针
    cout<<m_name<<" "<<m_age<<" "<<m_score<<endl;
}

int main(){
    student st1("abdusaimi",21,99.23);
    student st2=st1;
    student st3(st2);
    st1.display();
    st2.display();
    st3.display();
}
