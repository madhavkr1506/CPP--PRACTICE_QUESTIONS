// write c++ program to left rotate an array : 
#include<iostream>
#define size 5
using namespace std;

void printArray(int arr[]);
void rotateByOne(int arr[]);

int main(){
    int i, num;
    int arr[size];
    cout<<"enter five elements array = ";
    for (i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"enter number of times to left rotate = ";
    cin>>num;

    num = num%size;

    cout<<"array before rotation : \n"<<endl;
    printArray(arr);

    for (i=1;i<=num;i++){
        rotateByOne(arr);
    }
    cout<<"\narray after rotation : "<<endl;
    printArray(arr);
return 0;
}
void rotateByOne(int arr[]){
    int i,first;
    first = arr[0];
    for (i=0;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    arr[size-1]=first;
}

void printArray(int arr[]){
    int i;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<"\t";
    }
}