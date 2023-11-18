#include<iostream>
using namespace std;
void printarray(int arr[],int num){
    for(int i=0;i<num;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void heapify(int arr[],int num,int i){
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
void deletenode(int arr[],int &num){
    arr[0]=arr[num-1];
    num=num-1;
    heapify(arr,num,0);
}
void deletenodeinrange(int arr[],int &num,int key){
    for(int i=0;i<num;i++){
        if(arr[i] == key){
            arr[i]=arr[num-1];
            num=num-1;
            heapify(arr,num,i);
            i--;
        }
    }
}
void remove(int arr[],int & num,int key){
    int size=num;
    num=0;
    for(int i=0;i<size;i++){
        if(arr[i] < key){
            arr[num]=arr[i];
            num++;
        }
    }
}

void deleteOutsideRange(int arr[], int &num, int start, int last) {
    int newSize = 0;
    for (int i = 0; i < num; i++) {
        if (arr[i] >= start && arr[i] <= last) {
            arr[newSize++] = arr[i];
        }
    }
    num = newSize;
}

void maxheap(int arr[],int num){
    for(int i=(num-2)/2;i>=0;i--){
        heapify(arr,num,i);
    }
}
int main(){
    int num;
    cin>>num;
    int arr[num];
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }
    cout<<endl;

    maxheap(arr,num);
    int start;
    cin>>start;
    int last;
    cin>>last;
    // for(int i=start;i<=last;i++){
    //     deletenodeinrange(arr,num,i);
    // }
    // int key;
    // cin>>key;
    // deletenodeinrange(arr,num,key);
    // remove(arr,num,key);
    // deletenode(arr,num);
    deleteOutsideRange(arr,num,start,last);
    printarray(arr,num);
return 0;
}