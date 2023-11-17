#include<iostream>
using namespace std;
int main(){
    int num;
    cin>>num;
    int arr[num];
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }
    for(int i=0;i<num;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int index;
    cin>>index;
    for(int i=0;i<index;i++){
        int first;
        first=arr[0];
        for(int i=0;i<num;i++){
            arr[i]=arr[i+1];
        }
        arr[num-1]=first;
    }
    for(int i=0;i<num;i++){
        cout<<arr[i]<<" ";
    }
return 0;
}