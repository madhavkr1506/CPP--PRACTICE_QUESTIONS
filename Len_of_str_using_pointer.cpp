// write c++ program to find length of string using pointer : 
#include<iostream>
#define MAX_SIZE 100
using namespace std;
int main(){
    char text[MAX_SIZE];
    char *str=text;
    int count = 0;
    cout<<"enter any string = "<<endl;
    cin>>text;

    while(*(str++)!='\0')count++;

    cout<<"length of "<<text<<" is "<<count;
return 0;
}