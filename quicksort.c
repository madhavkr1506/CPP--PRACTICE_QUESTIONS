#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int partition();
void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}
void quicksort(int arr[],int low,int high){
    int positionindex;
    if(low<high){
        positionindex=partition(arr,low,high);
        quicksort(arr,low,positionindex-1);
        quicksort(arr,positionindex+1,high);
    }
}
int partition(int arr[],int low,int high){
    int pivot = arr[low];
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
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printarray(arr,n);
    printf("\n");
    quicksort(arr,0,n-1);
    printarray(arr,n);
}