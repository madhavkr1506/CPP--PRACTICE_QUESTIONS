#include<iostream>
#include<algorithm>
using namespace std;
void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void insert(int arr[],int& n,int value){
    n=n+1;
    arr[n-1]=value;
    int i=n-1;
    while(i>0){
        int parent =(i - 1)/2;
        if(arr[i]>arr[parent]){
            swap(arr[i],arr[parent]);
            i=parent;
        }
        else{
            break;
        }
    }
}
void deletion(int arr[],int& n){
    if(n==0){
        return;
    }
    arr[0]=arr[n-1];
    n=n-1;
    int i=0;
    while (true)
    {
        int left=2*i+1;
        int right=2*i+2;
        int largest = i;
        if(left < n && arr[left] > arr[largest]){
            largest=left;
        }
        if(right < n && arr[right] > arr[largest]){
            largest=right;
        }
        if(largest != i){
            swap(arr[i],arr[largest]);
            i=largest;
        }
        else{
            break;
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
    printarray(arr,num);
    // int key = 15;
    // insert(arr,num,key);
    // printarray(arr,num);
    deletion(arr,num);
    printarray(arr,num);
return 0;
}