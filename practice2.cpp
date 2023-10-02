#include<iostream>
using namespace std;
int binarysearch(int arr[],int x,int left,int right){
    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]==x){
            return mid;
        }
        else if(arr[mid]<x){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return -1;
}
int selectionsort();
int selectionsort(int arr[], int n){
    int i,j,sel;
    for(i=0;i<n-1;i++){
        sel=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[sel])
                sel=j;
        }
        if(sel!=i)
            swap(arr[sel],arr[i]);
        cout<<i+1<<" : ";
        for(int k=0;k<n;k++){
            cout<<arr[k]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int size;
    cin>>size;
    int arr[size];
    for (int i=0;i<size;i++){
        cin>>arr[i];
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    selectionsort(arr,size);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int x;
    cin>>x;
    int a=binarysearch(arr,x,0,size-1);
    if(a!=-1){
        cout<<a;
    }
    else{
        cout<<"error";
    }

}