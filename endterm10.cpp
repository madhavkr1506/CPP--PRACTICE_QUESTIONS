#include<iostream>
using namespace std;
void printarray(int arr[],int num){
    for(int i=0;i<num;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void bubblesort(int arr[],int num){
    for(int i=0;i<num-1;i++){
        for(int j=0;j<num-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                cout<<"sorting : "<<j+1<<" ";
                printarray(arr,num);
            }
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
        bubblesort(arr,num);
        printarray(arr,num);

return 0;
}