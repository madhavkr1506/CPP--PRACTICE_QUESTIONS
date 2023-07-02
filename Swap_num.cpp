// Write a program to swap two number.

#include<iostream>
using namespace std;
int main(){
    cout<<"Swap two number"<<endl;
    int num1,num2,temp;
    cout<<"enter num1 = "<<endl;
    cin>>num1;
    cout<<"enter num2 = "<<endl;
    cin>>num2;
    temp=num2;
    num2=num1;
    num1=temp;
    cout<<"after swapping the first number is = "<<num1<<endl;
    cout<<"after swapping the second number is = "<<num2<<endl;
return 0;
}