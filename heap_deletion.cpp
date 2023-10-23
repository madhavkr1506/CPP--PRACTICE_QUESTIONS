#include<iostream>
#define MAX 1000
using namespace std;
void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void heapify(int arr[],int n,int i){
    int largest = i;
    int l=2*i + 1;
    int r=2*i + 2;
    if(l<n && arr[l]>arr[largest]){
        largest = l;
    }
    if(r<n && arr[r]>arr[largest]){
        largest = r;
    }
    if(largest != i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
void deletion(int arr[],int& n){
    int lastelement = arr[n-1];
    arr[0]=lastelement;
    n=n-1;
    heapify(arr,n,0);
}
int main(){
    int arr[MAX] = {10,5,3,2,4};
    int num=5;
    printarray(arr,num);  
    deletion(arr,num);
    printarray(arr,num);
return 0;
}