// write c++ program to count number of each elements in an array : 
#include<iostream>
using namespace std;
int main(){
    int arr[100],frequency[100];
    int i,j,count,num;

    cout<<"enter size of array = ";
    cin>>num;

    cout<<"enter elements in array = ";
    for(i=0;i<num;i++){
        cin>>arr[i];
        frequency[i]=-1;
    }
    for(i=0;i<num;i++){
        count=1;
        for(j=i+1;j<num;j++){
            if(arr[i]==arr[j]){
                count++;
                frequency[j]=0;
            }
        }
        if(frequency[i]!=0){
            frequency[i]=count;
        }
    }
    cout<<"\nfrequency of all elements of array = \n";
    for(i=0;i<num;i++){
        if(frequency[i]!=0){
            cout<<arr[i]<<" occurs "<<frequency[i]<<" times\n";
        }
    }
return 0;
}