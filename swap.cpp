#include<iostream>
#include"template.h"
using namespace std;

//template int add<int>(int t1,int t2);

int main(){

    char name[]={"abdusaimi"};
    Array<char> tname(name,sizeof(name)/sizeof(char));
    tname.show();
    int num[20]={1,2,3,4,5,6,7,8,6,5,54,0};//一定要给定长，以便让更容易定出，时int类型的数组
    Array<int> tnum(num,20);
    tnum.show();
    return 0;
}