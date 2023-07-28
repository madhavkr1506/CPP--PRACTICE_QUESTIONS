// write c++ program to delete all duplicate elements from an array : 
#include<iostream>
#define MAX_SIZE 100
using namespace std;
int main(){
    int arr[MAX_SIZE];
    int num;
    int i,j,k;

    cout<<"enter size of the array = ";
    cin>>num;

    cout<<"enter elements in array = ";
    for(i=0;i<num;i++){
        cin>>arr[i];
    }

    for(i=0;i<num;i++){
        for(j=i+1;j<num;j++){
            if(arr[i]==arr[j]){
                for(k=j;k<num;k++){
                    arr[k]=arr[k+1];
                }
                num--;
                j--;
            }
        }
    }
    cout<<"\narray elements after deleting duplicates = ";
    for(i=0;i<num;i++){
        cout<<"\t"<<arr[i];
    }
return 0;
}