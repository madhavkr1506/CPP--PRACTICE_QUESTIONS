// write a c++ program that reads the integer n and prints its factorial : 
#include<iostream>
using namespace std;
long long factorial(int num){
    if (num == 0){
        return 1;
    }
    else{
        return num * factorial(num-1);
    }
}
int main(){
    int num;
    cin>>num;
    cout<<factorial(num)<<endl;
return 0;
}