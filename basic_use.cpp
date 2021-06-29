#include<iostream>
#include<fstream>
using namespace std;

int main(){
    const char* str="abdusaimi sawutiwqewqee";
    fstream fs;
    fs.open("fi.txt",ios::out);
    fs.write(str,20);
    fs.close();
   

   fstream inFile;
    inFile.open("f1.txt", ios::out);
    if (inFile)  //条件成立，则说明文件打开成功
        inFile.close();
    else
        cout << "test.txt doesn't exist" << endl;
}

