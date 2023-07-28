// How to count total number of negative elements in array in c++ :
#include<iostream>
#define MAX_SIZE 100
using namespace std;
int main(){
    int arr[100];
    int i, num, count=0;
    cout<<"enter size of the array = ";
    cin>>num;

    cout<<"enter elements in the array = ";
    for(i=0;i<num;i++){
        cin>>arr[i];
    }

    for(i=0;i<num;i++){
        if(arr[i]<0){
            count++;
        }
    }
    cout<<"total number of negative elements are = "<<count;
return 0;
}
