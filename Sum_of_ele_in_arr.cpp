// write c++ program to print sum of elements in an array : 
#include<iostream>
#define MAX_SIZE 100
using namespace std;
int main(){
    int arr[MAX_SIZE];
    int i, num, sum=0;
    cout<<"enter size of the array = ";
    cin>>num;
    cout<<"enter "<<num<<" elements in the array = "<<endl;

    for (i=0;i<num;i++){
        cin>>arr[i];
    }

    for(i=0;i<num;i++){
        sum=sum+arr[i];
    }

    cout<<"sum of all elements of array = "<<sum;
return 0;
}