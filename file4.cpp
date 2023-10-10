#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
int main(){
    ifstream read;
    read.open("file1.txt");
    ofstream write;
    write.open("file2.txt");
    while(read.eof()==0){
        string input;
        getline(read,input);
        write<<input<<endl;
    }
return 0;
}