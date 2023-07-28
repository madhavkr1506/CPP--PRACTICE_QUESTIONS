// write c++ program to copy one string to another string : 
#include<iostream>
#define MAX_SIZE 100
using namespace std;
int main(){
    char text1[MAX_SIZE],text2[MAX_SIZE];
    char *str1=text1;
    char *str2=text2;

    cout<<"enter any string : "<<endl;
    cin>>text1;

    while(*(str2++)=*(str1++));
    
    cout<<"first string = "<<text1<<endl;
    cout<<"second string = "<<text2<<endl;
return 0;
}