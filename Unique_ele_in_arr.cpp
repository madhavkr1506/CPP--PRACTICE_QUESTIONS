// write c++ program to print all unique element in an array : 
#include<iostream>
using namespace std;
int main(){
    int arr[100],size,isUnique;
    int i,j,k;
    cout<<"enter size of array = ";
    cin>>size;

    cout<<"enter elements in array = ";
    for(i=0;i<size;i++){
        cin>>arr[i];
    }
    for(i=0;i<size;i++){
        isUnique=1;
        for(j=i+1;j<size;j++){
            if(arr[i]==arr[j]){
                for(k=j;k<size-1;k++){
                    arr[k]=arr[k+1];
                }
                size--;
                j--;
                isUnique=0;
            }
        }
        /* if array element is not unique then also remove the current elements */
        if(isUnique!=1){
            for(j=i;j<size-1;j++){
                arr[j]=arr[j+1];
            }
            size--;
            i--;
        }
    }
    // printing all unique elements in array : 
    cout<<"all unique elements in an array are = \t";
    for(i=0;i<size;i++){
        cout<<arr[i]<<"\t";
    }
return 0;
}