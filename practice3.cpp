#include<iostream>
using namespace std;
int bubblesort();
int bubblesort(string arr[],int n){
    int i,j;
    bool bubble;
    for(i=0;i<n-1;i++){
        bubble=false;
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                bubble = true;
            }
        }
        if(! bubble){
            break;
        }
        cout<<i+1<<" : ";
        for(int k=0;k<n;k++){
            cout<<arr[k]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    string arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    bubblesort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}