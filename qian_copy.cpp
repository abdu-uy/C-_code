#include<iostream>
using namespace std;


class base{
    public:
        base():m_a(0),m_b(0){}//传参型构造函数初始化
        base(int a,int b):m_a(a),m_b(b){}//传参初始化
        void disp(){
            cout<<m_a<<" "<<m_b;
        }
    private:
        int m_a;
        int m_b;
};


int main(){
    base b1;
    base b2(20,30);
    b1=b2;
    b1.disp();
    b2.disp();
    
}