// Find first and last position of element in sorted array : 
#include<iostream>
using namespace std;
void findfirstandlast(int arr[],int n,int x){
    int first = -1,last = -1;
    for(int i=0;i<n;i++){
        if(x != arr[i]){
            continue;
        }
        if(first == -1){
            first = i;
        }
        last = i;
    }
    if (first != -1){
        cout<<"first occurence = "<<first<<"\nlast occurence = "<<last;
    }
    else{
        cout<<"not found";
    }
}
int main(){
    int n;
    cout<<"How many elements you want to enter in an array = ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter "<<i<<" element of an array : ";
        cin>>arr[i];
    }
    int search;
    cout<<"Please enter the elements that you want to search inside the given array : ";
    cin>>search;
    findfirstandlast(arr,n,search);

return 0;
}