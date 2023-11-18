#include<iostream>
#include<string>
using namespace std;
void heapify(string arr[],int num,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left < num && arr[left] > arr[largest]){
        largest=left;
    }
    if(right < num && arr[right] > arr[largest]){
        largest=right;
    }
    if(largest != i){
        swap(arr[i],arr[largest]);
        heapify(arr,num,largest);
    }
}
void maxheap(string arr[],int num){
    for(int i=(num-2)/2;i>=0;i--){
        heapify(arr,num,i);
    }
}
void heapsort(string arr[],int num){
    for(int i=(num-1);i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
void printarray(string arr[],int num){
    for(int i=0;i<num;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int num;
    cin>>num;
    string arr[num];
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }
    maxheap(arr,num);
    heapsort(arr,num);
    printarray(arr,num);
return 0;
}