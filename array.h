#include <iostream>
using namespace std;

class Array{
public:
    Array(int length = 0);
    ~Array();
public:
    int & operator[](int i);
    const int & operator[](int i) const;
public:
    int length() const { return m_length; }
    void display() const;
private:
    int m_length;  //数组长度
    int *m_p;  //指向数组内存的指针
};

Array::Array(int len):m_length(len){
    if(len==0){
        m_p=NULL;
    }
    else{
        m_p=new int[len];
    }
}

Array::~Array(){
    delete[] m_p;
}

 int& Array::operator[](int i){
    return m_p[i];
}

const int & Array::operator[](int i) const{
    return m_p[i];
}

void Array::display() const{
    for(int i = 0; i < m_length; i++){
        if(i == m_length - 1){
            cout<<m_p[i]<<endl;
        }else{
            cout<<m_p[i]<<", ";
        }
    }
}

