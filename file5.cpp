#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
int main(){
    ofstream write;
    write.open("file1.txt",ios::app);
    if(!write.is_open()){
        cout<<"fail to open this file";
        return 1;
    }
    string name;
    cout<<"Name = ";
    getline(cin,name);
    write<<"\nMy name is "+name;
    write.close();
}