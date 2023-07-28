// write c++ program to find hcf of two numbers : 
#include<iostream>
using namespace std;
int main(){
    int i,num1,num2,min,HCF=1;
    cout<<"enter any two numbers : ";
    cin>>num1;
    cin>>num2;
    min=(num1<num2)?num1:num2;
    for(i=1;i<=min;i++){
        if(num1%i==0 && num2%i==0){
            HCF=i;
        }
    }
    cout<<"hcf of "<<num1<<" and "<<num2<<" is "<<HCF;
return 0;
}