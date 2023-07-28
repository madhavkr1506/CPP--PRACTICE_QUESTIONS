// write c++ program to count total duplicate elements in an array : 
#include<iostream>
using namespace std;
int main(){
    int arr[100];
    int i,j,n;
    int count=0;
    cout<<"enter size of the array = \n";
    cin>>n;

    cout<<"enter elements in the array = \n";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
                break;
            }
        }
    }
    cout<<"\ntotal number of duplicate elements found in array = "<<count;
return 0;
}