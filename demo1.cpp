#include<stdio.h>



int main(){


    float *p=new float(2.5f);

    printf("%f %p",*p,p);
    delete p;
    p=new float [10];

    delete p;

}