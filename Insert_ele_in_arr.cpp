// write c++ program to insert an element in array : 
#include<iostream>
#define MAX_SIZE 100
using namespace std;
int main(){
    int arr[100];
    int i,num,size,position;
    cout<<"enter size of the array : ";
    cin>>size;
    cout<<"enter elements in array : ";
    for(i=0;i<size;i++){
        cin>>arr[i];
    }

    cout<<"enter element to insert : ";
    cin>>num;
    cout<<"enter the element position : ";
    cin>>position;

    if(position>size+1 || position<=0){
        cout<<"Invalid position! please enter position between 1 to "<<num;
    }
    else{
        for(i=size;i>=position;i--){
            arr[i]=arr[i-1];
        }
        arr[position-1]=num;
        size++;

        cout<<"array elements after insertion : ";
        for(i=0;i<size;i++){
            cout<<arr[i]<<"\t";
        }
    }
return 0;
}