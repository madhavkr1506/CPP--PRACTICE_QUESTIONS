#include<iostream>
using namespace std;
void  printarray(int arr[],int n){
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
void quicksort(int arr[],int low,int high){
    int indexpos;
    if(low<high){
        indexpos=partition(arr,low,high);
        quicksort(arr,low,indexpos-1);
        quicksort(arr,indexpos+1,high);
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
    quicksort(arr,0,num-1);
    cout<<endl;
    printarray(arr,num);
}