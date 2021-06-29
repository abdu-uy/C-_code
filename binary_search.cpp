#include<iostream>
using namespace std;


int binary_Search(int num[], int target){
    int left=0;
    int right=4;
 
    while(left<=right){
        int mid=(left+right)/2;

        if(num[mid]==target){
            return mid;
        }
        else if(num[mid]>target){
            right=mid-1;
        }
        else if(num[mid]<target){
            left=mid+1;
        }
        }
        return -1;
}

int main(){
    int num[5]={12,23,34,45,56};
    int index=binary_Search(num,45);
    cout<<index;
}