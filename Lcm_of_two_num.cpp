// write c++ program to find lcm of two numbers : 
#include<iostream>
using namespace std;
int main(){
    int i,num1,num2,max,cm=1;
    cout<<"enter any two numbers : ";
    cin>>num1;
    cin>>num2;
    max=(num1>num2)?num1:num2;
    i=max;

    while(1){
        if(i%num1==0 && i%num2==0){
            cm=i;
            break;
        }
        i+=max;
    }
    cout<<"lcm of "<<num1<<" and "<<num2<<" is "<<cm;
return 0;
}