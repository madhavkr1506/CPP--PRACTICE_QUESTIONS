#include<iostream>
using namespace std;
void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void heapifyinsert(int arr[],int n,int i){
    int parent=(i-1)/2;
    if(parent >= 0){
        if(arr[i]<arr[parent]){
            swap(arr[i],arr[parent]);
            heapifyinsert(arr,n,parent);
        }
    }
}
void insertnode(int arr[],int &n,int value){
    n=n+1;
    arr[n-1]=value;
    heapifyinsert(arr,n,n-1);
}
void heapifydelete(int arr[],int n,int i){
    int smallest=i;
    int left=2 * i + 1;
    int right=2 * i + 2;
    if(left < n && arr[left] < arr[smallest]){
        smallest=left;
    }
    if(right < n && arr[right] < arr[smallest]){
        smallest=right;
    }
    if(smallest != i){
        swap(arr[i],arr[smallest]);
        heapifydelete(arr,n,smallest);
    }
}
void deletenode(int arr[],int &n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            arr[i]=arr[n-1];
            n=n-1;
            heapifydelete(arr,n,i);
            i--;
        }
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
    printarray(arr,n);
    int start;
    cin>>start;
    int end;
    cin>>end;
    for(int i=start;i<=end;i++){
        deletenode(arr,n,i);
    }
    printarray(arr,n);
return 0;
}