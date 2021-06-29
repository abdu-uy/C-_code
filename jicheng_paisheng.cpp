#include<iostream>
using namespace std;

class people
{
protected:
   char* m_name;
   int m_age;
public:

    void set_name( char* name);
    void set_age(int age);
    char* get_name();
    int get_age();
    

    
    
};

void people::set_name( char* name){
    m_name=name;
}
void people::set_age(int age){
    m_age=age;
}
char* people::get_name(){return m_name;}
int people::get_age(){return m_age;}

class stu:public people{
private:
    float m_score;
    using people::get_age;//将public成员改成private型的成元函数
public:
    using people::m_name;//同下
    using people::m_age;//将protected 成员改成public;
    void set_score(float score);
    int get_score();
    friend ostream& operator<<(ostream &out,stu &stu);
};
void stu::set_score(float score){
    m_score=score;
}
int stu::get_score(){
    return m_score;
}


ostream& operator<<(ostream &out,stu &stu){
    out<<stu.get_name()<<" "<<stu.get_age()<<" "<<stu.get_score()<<endl;
    return out;
}

int main(){
    stu s1;
    char* name[30]={"abdusaimi"};
    s1.set_name(*name);
    s1.set_age(24);
    s1.set_score(99);
    cout<<s1;
}

