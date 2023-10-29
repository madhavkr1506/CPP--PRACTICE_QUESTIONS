#include<iostream>
using namespace std;
void printarray(int arr[],int num){
    for(int i=0;i<num;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void maxheapify(int arr[],int n,int i){
    int left=2 * i + 1;
    int right=2 * i + 2;
    int largest=i;
    if(left < n && arr[left] > arr[largest]){
        largest=left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest=right;
    }
    if(largest != i){
        swap(arr[i],arr[largest]);
        maxheapify(arr,n,largest);
    }
}
void buildmaxheap(int arr[],int n){
    for(int i=(n-2)/2;i>=0;i--){
        maxheapify(arr,n,i);
    }
}
int main(){
    int num;
    cin>>num;
    int arr[num];
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }
    buildmaxheap(arr,num);
    printarray(arr,num);
return 0;
}