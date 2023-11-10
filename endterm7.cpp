#include<iostream>
using namespace std;
void printarray(int arr[],int num){
    for(int i=0;i<num;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void merge(int array[],int mid,int low,int high){
    int i=low;
    int j=mid+1;
    int k=low;
    int array2[100];
    while(i<=mid && j<=high){
        if(array[i]<array[j]){
            array2[k]=array[i];
            i++;
            k++;
        }
        else{
            array2[k]=array[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
        array2[k]=array[i];
        i++;
        k++;
    }
    while(j<=high){
        array2[k]=array[j];
        j++;
        k++;
    }

    for(int i=low;i<=high;i++){
        array[i]=array2[i];
    }
}
void mergesort(int arr[],int low,int high){
    int mid;
    if(low<high){
        mid=(low + high) / 2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,mid,low,high);
    }
}
int main(){
    int num;
    cin>>num;
    int array[num];
    for(int i=0;i<num;i++){
        cin>>array[i];
    }
    mergesort(array,0,num-1);
    printarray(array,num);
return 0;
}