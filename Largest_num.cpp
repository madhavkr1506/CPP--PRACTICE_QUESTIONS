// write c++ program to find largest number :
#include<iostream>
using namespace std;
int main(){
    int num1,num2,num3,largest;
    cout<<"enter three numbers : ";
    cin>>num1>>num2>>num3;

    largest=num1>num2?(num1>num3?num1:num3):(num2>num3?num2:num3);
    cout<<largest<<" is the largest number.";
return 0;
}