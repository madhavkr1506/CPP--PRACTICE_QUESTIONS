#include<iostream>
using namespace std;
void printarray(int arr[],int num){
    for(int i=0;i<num;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void heapify(int arr[],int n,int i){
    int parent=(i-1)/2;
    if(parent >= 0){
        if(arr[i]>arr[parent]){
            swap(arr[i],arr[parent]);
            heapify(arr,n,parent);
        }
    }
}
void insertnode(int arr[],int &n,int value){
    n=n+1;
    arr[n-1]=value;
    heapify(arr,n,n-1);
}
int main(){
    int num;
    cin>>num;
    int arr[num];
    int n=0;
    for(int i=0;i<num;i++){
        int data;
        cin>>data;
        insertnode(arr,n,data);
    }
    printarray(arr,n);
return 0;
}