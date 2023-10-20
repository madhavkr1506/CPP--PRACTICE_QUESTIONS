#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    ifstream read;
    read.open("mooc.txt");
    // read<<"hello madhav\n";
    // read<<"hello krishna\n";
    // read.close();
    // ifstream write;
    // write.open("mooc.txt");
    // while(write.eof()==0){
    //     string string1;
    //     getline(write,string1);
    //     cout<<string1<<endl;
    // }
    string string2;
    int totalline=0;
    int linecount=0;
    while(getline(read,string2)){
        totalline++;
    }
    read.clear();
    read.seekg(0,ios::beg);
    ofstream write;
    write.open("mooc1.txt");
    while(read.eof()==0){
        linecount++;
        string string1;
        getline(read,string1);
        write<<string1<<endl;
        if(linecount >= totalline / 2){
            break;
        }
    }
return 0;
}