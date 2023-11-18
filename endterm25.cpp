#include<iostream>
using namespace std;
void printarray(int arr[],int num){
    for(int i=0;i<num;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// void insert_heapify(int arr[],int & num,int i){
//     int parent=(i-1)/2;
//     if(parent>=0){
//         if(arr[i]>arr[parent]){
//             swap(arr[i],arr[parent]);
//             insert_heapify(arr,num,parent);
//         }
//     }
// }

// void insertnode(int arr[],int& num,int value){
//     num=num+1;
//     arr[num-1]=value;
//     insert_heapify(arr,num,num-1);
// }


void heapify(int arr[],int num,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<num && arr[left] < arr[largest]){
        largest=left;
    }
    if(right<num && arr[right] < arr[largest]){
        largest=right;
    }
    if(largest != i){
        swap(arr[i],arr[largest]);
        heapify(arr,num,largest);
    }
}

void deletenode(int arr[],int & num){
    arr[0]=arr[num-1];
    num=num-1;
    heapify(arr,num,0);
}


void maxheap(int arr[],int num){
    for(int i=(num-2)/2;i>=0;i--){
        heapify(arr,num,i);
    }
}



void heapsort(int arr[],int num){
    for(int i=num-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

int main(){
    int num;
    cin>>num;
    int arr[num];
    // int n=0;
    for(int i=0;i<num;i++){
        // int data;
        // cin>>data;
        // insertnode(arr,n,data);
        cin>>arr[i];
    }
    maxheap(arr,num);
    heapsort(arr,num);

    // deletenode(arr,num);
    printarray(arr,num);
}