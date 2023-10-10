#include<iostream>
#include<fstream>
using namespace std;
int main(){
    cout<<"lets have some kind of fun\n";
    ofstream out("file1.txt");
    cout<< "Name = ";
    string st="please enter your name = ";
    string name;
    getline(cin, name);
    out<<st;
    out<<name;
    out.close();
    cout<<"things that you have enterder inside file\n";
    string display;
    ifstream in("file1.txt");
    // in>>display;
    getline(in,display);
    cout<<display;
    in.close();

return 0;
}