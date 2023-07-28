// write c++ program to accept two integers and check they are equal or not : 
#include<iostream>
using namespace std;
int main(){
    int num1,num2;
    cout<<"input the values for number1 and number2 : ";
    cin>>num1>>num2;
    if(num1==num2){
        cout<<"number1 and number2 are equal";
    }
    else{
        cout<<"number1 and number2 are not equal";
    }
return 0;
}