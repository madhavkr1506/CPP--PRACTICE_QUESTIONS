#include<iostream>
#include<vector>
using namespace std;
void printarray(int arr[],int num){
    for(int i=0;i<num;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void insertion(int arr[],int n,int value){
    n=n+1;
    arr[n-1]=value;
    int i=n-1;
    while(i>0){
        int parent=(i-1)/2;
        if(arr[i]<arr[parent]){
            swap(arr[i],arr[parent]);
            i=parent;
        }
        else{
            break;
        }
    }
}

int main(){
    int num;
    cin>>num;
    // int arr[num];
    int * arr=new int[num];
    for(int i=0;i<num;i++){
        int data;
        cin>>data;
        insertion(arr,i,data);
    }
    printarray(arr,num);
    delete[] arr;
return 0;
}