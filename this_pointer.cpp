#include<iostream>
using namespace std;

class student{
private:
    char* name;
    int age;
    int score;
public:
    void setname(char* name);
    void setage(int age);
    void serscore(int score);
    void show();
};

void student::setname(char* name){
    this->name=name;
}

void student::setage(int age){
    this->age=age;
}

void student::serscore(int score){
    this->score=score;
}

void student::show(){
    cout<<this->name<<" "<<this->age<<" "<<this->score<<endl;
}


int main(){
    student *st;//先创建该类型指针，再给分配给内存空间
    st=new student;
    st->setname("abdu");
    st->setage(22);
    st->serscore(99);
    st->show();
    delete st;
    return 0;
}