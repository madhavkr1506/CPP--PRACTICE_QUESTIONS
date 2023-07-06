// write c++ program to put even and odd elements of array in separate array : 
#include<iostream>
#define MAX_SIZE 100 
using namespace std;

void printArray(int arr[], int len);

int main(){
    int arr[MAX_SIZE];
    int even[MAX_SIZE];
    int odd[MAX_SIZE];

    int evenCount,oddCount;
    int i,size;

    cout<<"enter size of the array = ";
    cin>>size;

    cout<<"enter elements in the array = ";
    for (i=0;i<size;i++){
        cin>>arr[i];
    }
    evenCount=0;
    oddCount=0;
    for (i=0;i<size;i++){
        // if arr[i] is odd
        if (arr[i] & 1){
            odd[oddCount]=arr[i];
            oddCount++;
        }
        else{
            even[evenCount]=arr[i];
            evenCount++;
        }
    }
    cout<<"\nelements of even array = ";
    printArray(even, evenCount);

    cout<<"\nelements of odd array = ";
    printArray(odd, oddCount);
return 0;
}

//logic
void printArray(int arr[], int len){
    int i;
    for (i=0;i<len;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
}
