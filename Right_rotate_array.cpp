// write c++ program to right rotate an array : 
#include<iostream>
# define size 5 //definr size of an array
using namespace std;
void printArray(int arr[]);
void rotateByOne(int arr[]);
int main(){
    int i,num;
    int arr[size];
    cout<<"enter five elements array = ";
    for (i=0;i<5;i++){
        cin>>arr[i];
    }
    cout<<"enter number of times to right rotate = ";
    cin>>num;
    
    // actual rotation
    num = num % size;

    // printing array before rotation
    cout<<"\narray befor rotation = \n"<<endl;
    printArray(arr);

    // rotate array n times
    for (i=1;i<=num;i++){
        rotateByOne(arr);
    }
    // printing array after rotation
    cout<<"\narray after rotation = \n"<<endl;
    printArray(arr); 
return 0;
}
void rotateByOne(int arr[]){
    int i,last;

    // sorting last elements of an array 
    last=arr[size-1];

    for (i=size-1;i>0;i--){
        //moving each elements to its right
        arr[i]=arr[i-1];
    }

    // coping last elements of arrayto first
    arr[0]=last;
}

//printing the given array
void printArray(int arr[]){
    int i;
    for (i=0;i<size;i++){
        cout<<arr[i]<<"\t";
    }
}