// write a c++ program to compute the sum of the two given integers and count the number of digits in sum value.
#include<iostream>
#include<sstream>
using namespace std;
int main(){
    int x,y;
    while (cin>>x>>y){
        stringstream str1;
        str1<<x+y;
        cout<<str1.str().size()<<endl;
    }
return 0;
}