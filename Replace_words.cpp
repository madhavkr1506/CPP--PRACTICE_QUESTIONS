// write a c++ program that replace all the words "dog" with "cat".
#include<iostream>
using namespace std;
int main(){
    string str;
    getline(cin, str);
    cout<<"original text : "<<str;
    for(int j = 0; j < (int)str.size(); j++){
        string key = str.substr(j, 3),repl;
        if (key == "fox"){
            repl = "cat";
            for(int k=0; k < 3; k++){
                str[j + k] = repl[k];
            }
        }
    }
    cout<<"\nnew text : "<<str<<endl;
return 0;
}