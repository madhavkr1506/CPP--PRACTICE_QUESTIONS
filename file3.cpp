#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int main(){
    ofstream input;
    input.open("file1.txt");
    input<<"this is information pannel \n";
    string name;
    cout<<"lets have some kind of fun \n";
    cout<<"Name = ";
    getline(cin,name);
    input<<"My name is " + name;
    input.close();

    ifstream output;
    output.open("file1.txt");
    string display;
    while(output.eof() == 0){
        getline(output,display);
        cout<<display<<endl;
    }
    // while(getline(output,display)){;
    //     cout<<display<<endl;
    // }
    output.close();

return 0;
}