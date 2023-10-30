#include<iostream>
using namespace std;
void printarray(int arr[],int num){
    for(int i=0;i<num;i++){
        cout<<arr[i] <<" ";
    }
    cout<<endl;
}
void heapify_up(int arr[],int num,int i){
    int parent = (i - 1)/2;
    if(parent >= 0){
        if(arr[i] > arr[parent]){
            swap(arr[i],arr[parent]);
            heapify_up(arr,num,parent);
        }
    }
}
// void heapify_up(int arr[],int num,int i){
//     int left=2 * i + 1;
//     int right=2 * i + 2;
//     int largest=i;
//     if(left < num && arr[left] > arr[largest]){
//         largest=left;
//     }
//     if(right < num && arr[right] > arr[largest]){
//         largest=right;
//     }
//     if(largest != i){
//         swap(arr[i],arr[largest]);
//         heapify_up(arr,num,largest);
//     }
// }
void insertnode(int arr[],int &num,int value){
    num=num+1;
    arr[num-1]=value;
    heapify_up(arr,num,num-1);
}
void buildmaxheap(int arr[],int num){
    for(int i=(num-2)/2;i>=0;i--){
        heapify_up(arr,num,i);
    }
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
    buildmaxheap(arr,n);
    printarray(arr,n);

return 0;
}