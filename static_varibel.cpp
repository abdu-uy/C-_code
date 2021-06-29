#include<iostream>
using namespace std;


class stu{
public:
    stu(char *name,int age,int scaore);
    void show();
private:
    static int m_total;
private:
    char* m_name;
    int m_age;
    int m_score;
};
void stu::show(){
    cout<<this->m_name<<" "<<this->m_age<<" "<<this->m_score<<" "<<m_total<<endl;
}

int stu::m_total=0;
stu::stu(char *name,int age,int score):m_name(name),m_age(age),m_score(score){
    m_total++;
}


int main(){
    stu st1("abdu",22,99);
    stu st2("zayir",33,98);
    stu st3("abduaini",44,97);

    st1.show();
    st2.show();
    st3.show();
    return 0;
}