// write c++ program to check a number is prime or not using while/for loop : 
#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int num,i,f;
    cout<<"enter any number : ";
    cin>>num;
    f=0;
    i=2;
    while(i<=num/2){
        if(num%i==0){
            f=1;
            break;
        }
        i++;
    }
    if(f==0){
        cout<<num<<" is a prime number"<<endl;
    }
    else{
        cout<<num<<" is not a prime number"<<endl;
    }
return 0;
}