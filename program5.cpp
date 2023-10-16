#include<iostream>
using namespace std;
void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    int temp;
    do{
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }while(i<j);
    temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;
    return j;
}
void quicksort(int arr[],int low, int high){
    int positionindex;
    if(low<high){
        positionindex=partition(arr,low,high);
        quicksort(arr,low,positionindex-1);
        quicksort(arr,positionindex+1,high);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    printarr(arr,n);
    quicksort(arr,0,n-1);
    cout<<endl;
    printarr(arr,n);
return 0;
}
