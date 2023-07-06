// write c++ program to find the reverse of an array : 
#include<iostream>
#define MAX_SIZE 100 // maximum size of the array
using namespace std;
int main(){
    int array[MAX_SIZE];
    int size,i;

    // reading size of array
    cout<<"enter size of the array = ";
    cin>>size;

    // reading array elements
    for (i=0;i<size;i++){
        cin>>array[i];
    }

    // printing array in reverse order
    cout<<"\nArray in reverse order : ";
    for (i=size-1;i>=0;i--){
        cout<<"\t"<<array[i];
    }
return 0;
}