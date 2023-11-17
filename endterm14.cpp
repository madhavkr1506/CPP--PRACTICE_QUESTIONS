#include<iostream>
using namespace std;
int delete_element(int arr[],int num,int search){
    int i;
    for(i=0;i<num;i++){
        if(arr[i]==search){
            break;
        }
    }
    if(i<num){
        for(int j=i;j<num;j++){
            arr[j]=arr[j+1];
        }
        num=num-1;
    }
    
    return num;
}
void printarray(int arr[],int num){
    for(int i=0;i<num;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int num;
    cin>>num;
    int arr[num];
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }
    printarray(arr,num);
    int key;
    cin>>key;
    num=delete_element(arr,num,key);
    printarray(arr,num);
return 0;
}