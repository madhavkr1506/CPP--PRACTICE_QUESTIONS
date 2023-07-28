// write c++ program to check leap year using conditional operator :
#include<iostream>
using namespace std;
int main(){
    int year;
    cout<<"enter any year = ";
    cin>>year;
    (year%4==0 && year%100!=0)?cout<<year<<" is a leap year":
    (year%400==0)?cout<<"leap year":cout<<year<<" is not leap year";
return 0;
}