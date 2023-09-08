#include<iostream>
using namespace std;
int sum(int& num1,int& num2){  // this is call by reference
    return num1+num2;
}
int main(){
    int num = 100;
    // reference is an alias to a data;
    // int x = num;
    // cout<<num<<endl;
    // cout<<x<<endl;
    // dataType& refName = variableName
    // int& x = num;
    // cout<<x<<endl;
    // cout<<&num<<" "<<&x<<endl;
    // x = 200;
    // cout<<num<<" "<<x<<endl;
    // cout<<&num<<" "<<&x<<endl;

    // 1. Call by value : 
    // sum(100,200);
    // int Total = sum(100,200);
    // cout<<Total<<endl;
    // 2. Call by reference : 
    int num1 = 300;
    int num2 = 500;
    int total = sum(num1,num2);   // this is still call by value
    cout<<total<<endl;
return 0;
}