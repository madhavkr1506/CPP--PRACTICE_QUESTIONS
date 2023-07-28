// write c++ program to sort array in ascending order : 
#include<iostream>
using namespace std;
int main(){
    const int SIZE = 10;
    int arr[SIZE] = {5,2,9,1,8,3,7,6,4,0};

    // bubble sort algorithm
    for(int i=0;i<SIZE-1;i++){
        for(int j=0;j<SIZE-i-1;j++){
            if(arr[j]>arr[j+1]){
                //swap elements
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    // print sorted array
    for(int i=0;i<SIZE;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
return 0;
}