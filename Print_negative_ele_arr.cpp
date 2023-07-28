// write c++ program to print all negative elements in an array : 
#include<iostream>
# define MAX_SIZE 100
using namespace std;
int main(){
    int arr[MAX_SIZE];
    int i, num;
    cout<<"enter size of the array = ";
    cin>>num;

    cout<<"enter elements in the array = ";
    for(i=0;i<num;i++){
        cin>>arr[i];
    }

    cout<<"all negative elements in an array are = ";
    for(i=0;i<num;i++){
        if (arr[i]<0){
            cout<<arr[i]<<"\t";
        }
    }
return 0;
}