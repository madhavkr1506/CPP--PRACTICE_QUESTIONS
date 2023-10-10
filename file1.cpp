#include<iostream>
#include<fstream>
using namespace std;
/*
there are some useful classes to deals with files in c++
1.fstreambase
2.ifstream-->derived from fstreambase
3.ofstream-->derived from fstreambase 
ofstream
*/
int main(){
    // using constructor write into a file
    string st;
    st="this a miracle, i can survive on earth\n";
    ofstream out("file1.txt");
    out<<st;
    // using constructor read from a file;
    string st2;
    ifstream in("file2.txt");
    // in>>st2;
    getline(in,st2);
    cout<<st2;

    
return 0;
}