//  write a c++ program that add up all the digits between two numbers : 
#include<iostream>
using namespace std;
int test(int x, int y){
    int digit_sum = 0;
    for (int i = x; i <= y; ++i){
        int p = i;
        while(p > 0){
            digit_sum += p % 10;
            p /= 10;
        }
    }
    return digit_sum;
}
int main(){
    int n1 = 39;
    int n2 = 41;
    cout<<"add up all the digits between "<<n1<<" and "<<n2<<" is : ";
    cout<<test(n1, n2)<<endl;
return 0;
}