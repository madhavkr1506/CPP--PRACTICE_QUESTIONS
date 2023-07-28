// write c++ program to find the largest among three variables using nested if : 
#include<iostream>
using namespace std;
int main(){
    int num1,num2,num3;
    cout<<"enter three numbers : "<<endl;
    cin>>num1>>num2>>num3;
    if(num1>=num2){
        if(num1>=num3){
            cout<<num1<<" is the largest number.";
        }
        else{
            cout<<num3<<" is the largest number.";
        }
    }
    else if(num2>=num3){
        cout<<num2<<" is the largest number.";
    }
    else{
        cout<<num3<<" is the largest number";
    }
return 0;
}