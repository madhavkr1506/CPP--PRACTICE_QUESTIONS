// write c++ program to check whether a number is armstrong number or not.
#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int num, sum = 0, i, r;
    cout<<"enter any number to calculate factorial = ";
    cin>>num;
    for(i=num;i>0;i=i/10){
        r = i % 10;
        sum = sum + r * r * r; 
    }
    if (num == sum){
        cout<<num<<" is an armstrong number."<<endl;
    }
    else{
        cout<<num<<" is not an armstrong number."<<endl;
    }
return 0;
}