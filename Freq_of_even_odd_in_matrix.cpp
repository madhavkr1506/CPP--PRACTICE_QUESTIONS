// write c++ program to find the frequency of odd and even numbers in the given matrix :
#include<iostream>
using namespace std;
int main(){
    static int arr[10][10];
    int i,j,x,y;
    int even,odd;
    cout<<"enter the order of the matrix\n";
    cin>>x;
    cin>>y;
    cout<<"enter the coefficients of matrix\n";
    even=0;
    odd=0;
    for(i=0;i<x;++i){
        for(j=0;j<y;++j){
            cin>>arr[i][j];
            if((arr[i][j]%2)==0){
                ++even;
            }
            else{
                ++odd;
            }
        }
    }
    cout<<"the given matrix is \n";
    for(i=0;i<x;++i){
        for(j=0;j<y;++j){
            cout<<" "<<arr[i][j];
        }
        cout<<"\n";
    }
    cout<<"\nthe frequency of occurance of odd number = "<<odd<<endl;
    cout<<"\nthe frequency of occurance of even number = "<<even<<endl;
return 0;
}