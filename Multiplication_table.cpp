// write a c++ program that takes a number as input and prints its multiplication table upto 10.
#include<iostream>
using namespace std;
int main(){
    cout<<"write a c++ program that takes a number as input and prints its multiplication table upto 10."<<endl;
    int num;
    cout<<"enter number as input = ";
    cin>>num;
    for (int i=1;i<11;i++){
        cout<<num<<" X "<<i<<" = "<<num*i<<endl;
    }
    cout<<endl;
    cout<<"multiplication table in reverse order"<<endl;
    for (int i=10;i>0;i--){
        cout<<num<<" X "<<i<<" = "<<num*i<<endl;
    }
return 0;
}