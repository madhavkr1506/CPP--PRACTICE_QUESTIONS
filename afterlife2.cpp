#include<iostream>
using namespace std;
void printarray(int arr[],int num){
    for(int i=0;i<num;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void heapifydel(int arr[],int n,int i){
    int largest=i;
    int left=2 * i + 1;
    int right=2 * i + 2;
    if(left < n && arr[left] > arr[largest]){
        largest=left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest=right;
    }
    if(largest != i){
        swap(arr[i],arr[largest]);
        heapifydel(arr,n,largest);
    }
}
void deletenode(int arr[],int &n){
    arr[0]=arr[n-1];;
    n=n-1;
    heapifydel(arr,n,0);
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
    deletenode(arr,n);
    printarray(arr,n);
return 0;
}