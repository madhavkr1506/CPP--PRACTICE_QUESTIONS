#include<iostream>
#define MAX 1000
using namespace std;
void heapify(int arr[],int n,int i){
    int parent = (i - 1) / 2;
    if(parent >= 0){
        if(arr[i] > arr[parent]){
            swap(arr[i],arr[parent]);
            heapify(arr,n,parent);
        }
    }
}
void insertion(int arr[],int& n, int key){
    n=n+1;
    arr[n-1]=key;
    heapify(arr,n,n-1);
}
void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[MAX]={10,5,3,2,4};
    int num=5;
    int key=15;
    printarray(arr,num);
    insertion(arr,num,key);
    printarray(arr,num);

}