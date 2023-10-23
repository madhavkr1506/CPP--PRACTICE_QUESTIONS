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
void heapifydel(int arr[],int n,int i){
    int largest=i;
    int l=2*i + 1;
    int r=2*i + 2;
    if(l<n && arr[l]>arr[largest]){
        largest=l;
    }
    if(r<n && arr[r]>arr[largest]){
        largest=r;
    }
    if(largest != i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
void deletion(int arr[],int & n){
    int lastele=arr[n-1];
    arr[0]=lastele;
    n=n-1;
    heapifydel(arr,n,0);
}
void insertion(int arr[],int &n ,int key){
    n=n+1;
    arr[n-1]=key;
    heapify(arr,n,n-1);
}
int main(){
    int arr[100]={1,2,3,4,5};
    int num=5;
    int key=10;
    printarray(arr,num);
    insertion(arr,num,key);
    printarray(arr,num);
    deletion(arr,num);
    printarray(arr,num);
return 0;
}