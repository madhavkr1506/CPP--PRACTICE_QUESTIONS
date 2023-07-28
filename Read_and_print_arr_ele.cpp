// write c++ program to read and print elements of array : 
#include<iostream>
#define MAX_SIZE 100
using namespace std;
int main(){
    int arr[MAX_SIZE];
    int i,num;
    cout<<"enter size of the array : ";
    cin>>num;

    cout<<"enter "<<num<<" elements in the array : ";

    for(i=0;i<num;i++){
        cin>>arr[i];
    }

    cout<<"\nelements in array are : ";
    for(i=0;i<num;i++){
        cout<<arr[i]<<"\t";
    }
return 0;
}