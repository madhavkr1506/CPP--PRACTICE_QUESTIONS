// write c++ program to print first and last digit of any number : 
#include<iostream>
#include<math.h>

using namespace std;

int main(){
    int num,last;
    cout<<"enter any number : ";
    cin>>num;

    last=num%10;

    cout<<"the last digit of entered number : "<<last<<endl;

    while(num>=10){
        num=num/10;
    }
    cout<<"the first digit of entered number : "<<num<<endl;
return 0;
}