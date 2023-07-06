// write a c++ program that accepts various numbers and computes thje difference between the highest and lowest number.
// all the input numbers should be real numebrs between 0 to 1,000,000. the output (real number) may include an error of 0.01 or less.
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    double num[52];
    int c=0;
    while(cin>>num[c++]);
    sort(num,num+c-1);
    cout<<"difference between the highest and lowest numbers = ";
    cout<<num[c-2]-num[0]<<endl;
return 0;
}