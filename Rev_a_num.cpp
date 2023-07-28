// write c++ program to reverse a number using while and for loop : 
#include<iostream>
#include<math.h>

using namespace std;
int main(){
    int num,rev=0;

    cout<<"enter any number : ";
    cin>>num;

    // using while loop : 
    
    // while(num>0){
    //     rev=rev*10;
    //     rev=rev+num%10;
    //     num=num/10;
    // }


    // using for loop : 

    for(rev=0;num>0;num=num/10){
        rev=rev*10;
        rev=rev+num%10;
    }
    cout<<"reversed number is : "<<rev;
return 0;
}