#ifndef m
#define m

#include<iostream>
using namespace std;
struct student
{
    int id;
    char name[40];
    float score;
};

template<typename T1,typename T2>
T1 add(T1 t1,T2 t2){
    return t1+t2;
}

template<typename T>
void swab(T &t1,T &t2){

   T temp=t1;
   t1=t2;
   t2=temp;
}



template<typename T>
class Array{
private:
    int size;
    T* _ptr;
public:
    Array(T array[],int size);
    ~Array();
    void show();
};
template<typename T>
Array<T>::Array(T array[],int ze){
    _ptr=new T[ze];
    size=ze;
    for(int i=0;i<size;i++){
        _ptr[i]=array[i];
    }
}

template<typename T>
void Array<T>::show(){
    for(int i=0;i<size;i++){
        cout<<*(_ptr+i)<<" ";    
    }
    cout<<endl;
}
template<typename T>
Array<T>::~Array(){
    delete _ptr;
    cout<<"xigou"<<endl;
}


#endif