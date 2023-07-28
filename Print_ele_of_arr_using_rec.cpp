// write c++ program to print elements of an array using recursion : 
#include<iostream>
using namespace std;
#define MAX_SIZE 100

void PrintArray(int arr[],int start, int len);

int main(){
    int arr[MAX_SIZE];
    int num,i;
    cout<<"enter size of the array = ";
    cin>>num;

    cout<<"enter elements in the array = ";
    for(i=0;i<num;i++){
        cin>>arr[i];
    }

    cout<<"elements in the array = ";
    PrintArray(arr,0,num);
return 0;
}

void PrintArray(int arr[],int start,int len){
    if(start>=len){
        return;
    }
    cout<<arr[start]<<"\t";
    PrintArray(arr,start+1,len);
}