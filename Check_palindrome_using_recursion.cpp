// write c++ program to check palindrome number using recursion : 
#include<iostream>
#include<math.h>
using namespace std;

int reverseNumber(int num);
int isPalindrome(int num);

int main(){
    int num;
    cout<<"enter any number = ";
    cin>>num;

    if(isPalindrome(num)==1){
        cout<<num<<" is palindrome number";
    }
    else{
        cout<<num<<" is not palindrome number";
    }
return 0;
}

int isPalindrome(int num){
    if(num==reverseNumber(num)){
        return 1;
    }
return 0;
}

int reverseNumber(int num){
    int digit = (int)log10(num);
    if (num==0){
        return 0;
    }
    return ((num%10 * pow(10,digit))+reverseNumber(num/10));
}