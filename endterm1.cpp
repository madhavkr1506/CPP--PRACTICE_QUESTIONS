#include<iostream>
using namespace std;
void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left < n && arr[left] > arr[largest]){
        largest=left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest=right;
    }
    if(largest != i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
void maxheap(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
}
void deletenode(int arr[],int &n,int start,int end){
    int i=0;
    while(i<n){
        if(arr[i]<=start || arr[i]>=end){
            arr[i]=arr[n-1];
            n=n-1;
            heapify(arr,n,i);
        }
        else{
            i++;
        }
    }
}
void deletenodeafteravalue(int arr[],int &n,int value){
    int size=n;
    n=0;
    for(int i=0;i<size;i++){
        if(arr[i]<=value){
            arr[n]=arr[i];
            n++;
        }
    }
}
int main(){
    int num;
    cin>>num;
    int arr[num];
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }

    // int start,end;
    // cin>>start>>end;
    // deletenode(arr,num,start,end);
    int value;
    cin>>value;
    deletenodeafteravalue(arr,num,value);
    maxheap(arr,num);

    printarray(arr,num);
return 0;
}