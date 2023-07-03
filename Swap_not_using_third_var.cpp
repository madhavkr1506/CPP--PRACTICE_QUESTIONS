// write a program to swap the values of two variables not using third variable.

#include<iostream>
using namespace std;
int main(){
    cout<<"write a program to swap the values of two variables not using third variable"<<endl;
    int num1, num2,temp;
    cout<<"input first number = ";
    cin>>num1;
    cout<<"input second number = ";
    cin>>num2;
    num2=num2+num1;
    num1=num2-num1;
    num2=num2-num1;
    cout<<"after swapping the first number is = "<<num1<<endl;
    cout<<"after swapping the second number is = "<<num2<<endl;
return 0;
}