#include<iostream>
#include<cstdlib>
using namespace std;

class arry{
    public:
        arry(int len);
        arry(const arry &arr);
        ~arry();

        int operator[](int i)const{return m_p[i];}//read only
        int& operator[](int i){return m_p[i];}//write availebel
        int length()const{return m_len;}
        arry& operator=(const arry& arr);

    private:
    int m_len;
    int* m_p;
};


arry::arry(int len):m_len(len){
    m_p=(int*)calloc(len,sizeof(int));
}

arry::arry(const arry& arr){
    this->m_len=arr.m_len;
    this->m_p=(int*)calloc(m_len,sizeof(int));
    memcpy(this->m_p,arr.m_p,m_len*sizeof(int));
}

arry::~arry(){
    free(m_p);
}

arry& arry::operator=(const arry&arr){// copy construction
    if(this->m_p!=arr.m_p){
        this->m_len=arr.m_len;
        free(this->m_p);
        this->m_p=(int*)calloc(m_len,sizeof(int));
        memcpy(m_p,arr.m_p,m_len*sizeof(int));
    }
    return *this;
}

void printArray(const arry &arr){
    int len = arr.length();
    for(int i=0; i<len; i++){
        if(i == len-1){
            cout<<arr[i]<<endl;
        }else{
            cout<<arr[i]<<", ";
        }
    }
}


int main(){
    arry arr1(10);
    for(int i=0; i<10; i++){
        arr1[i] = i;
    }
    printArray(arr1);
   
    arry arr2(5);
    for(int i=0; i<5; i++){
        arr2[i] = i;
    }
    printArray(arr2);
    arr2 = arr1;  //调用operator=()
    printArray(arr2);
    arr1[3] = 234;  //修改arr1的数据不会影响arr2,说明此赋值是内存块赋值，不是指针指向同一个位置
    arr1[7] = 920;
    printArray(arr2);
   
    return 0;
}
