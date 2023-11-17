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
        int last;
        last=arr[num-1];
        for(int i=num-1;i>=0;i--){
            arr[i]=arr[i-1];
        }
        arr[0]=last;
    }
    for(int i=0;i<num;i++){
        cout<<arr[i]<<" ";
    }
return 0;
}