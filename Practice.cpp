#include<iostream>
using namespace std;
int binarySearch(int arr[],int x,int left,int right){
    while(left<=right){
        int mid = (left+right)/2;
        if(arr[mid]==x){
            return mid;
        }
        else if(arr[mid]<x){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return -1;
}
// int linearsearch(int arr[],int n,int x){
//     for(int i=0;i<n-1;i++){
//         if(arr[i]==x)
//             return i;
//     }
//     return -1;
// }
void selectionsort(int arr[],int n){
    int i,j,sel;
    for(int i=0;i<n-1;i++){
        sel=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[sel]){
                sel=j;
            }
        }
        if(sel != i){
            swap(arr[sel],arr[i]);
        }
        cout<<i+1<<" : ";
        for(int k=0;k<n;k++){
            cout<<arr[k]<<" ";
        }
        cout<<endl;
    }
}
// void insertionsort(int arr[],int n){
//     int i,j,key;
//     for(i=0;i<n-1;i++){
//         key=arr[i+1];
//         j=i;
//         while(j>=0 && arr[j]>key){
//             arr[j+1]=arr[j];
//             j=j-1;
//         }
//         arr[j+1]=key;
//         cout<<i+1<<" : ";
//         for(int k=0;k<n;k++){
//             cout<<arr[k]<<" ";
//         }
//         cout<<endl;
//     }

// }
// void bubblesort(int arr[],int n){
//     int i,j;
//     bool bubble;
//     for(i=0;i<n-1;i++){
//         bubble=false;
//         for(j=0;j<n-i-1;j++){
//             if(arr[j]>arr[j+1]){
//                 swap(arr[j],arr[j+1]);
//                 bubble = true;
//             }
//         }
//         if(! bubble){
//             break;
//         }
//         cout<<i+1<<" : ";
//         for(int k=0;k<n;k++){
//             cout<<arr[k]<<" ";
//         }
//         cout<<endl;
//     }
// }
int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    // cout<<endl;
    // bubblesort(arr,size);
    // for(int i=0;i<size;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // insertionsort(arr,size);
    // for(int i=0;i<size;i++){
    //     cout<<arr[i]<<" ";
    // }
    cout<<endl;
    selectionsort(arr,size);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    // cout<<endl;
    // int x;
    // cin>>x;
    // int a=linearsearch(arr,size,x);
    // cout<<a;
    cout<<endl;
    int x;
    cin>>x;
    int a=binarySearch(arr,x,0,size-1);
    if(a!=-1){
        cout<<a;
    }
    else{
        cout<<"error";
    }
return 0;
}



// #include <iostream>

// void bubbleSort(int arr[], int n) {
//     for (int i = 0; i < n - 1; i++) {
//         // Flag to optimize the algorithm by stopping if no swaps are made in a pass
//         bool swapped = false;

//         // Last i elements are already in place, so we don't need to check them
//         for (int j = 0; j < n - i - 1; j++) {
//             // Swap if the element found is greater than the next element
//             if (arr[j] > arr[j + 1]) {
//                 std::swap(arr[j], arr[j + 1]); // Swap the elements
//                 swapped = true;
//             }
//         }

//         // If no two elements were swapped in the inner loop, the array is sorted
//         if (!swapped) {
//             break;
//         }

//         // Print the current state of the array after this pass
//         std::cout << "Pass " << i + 1 << ": ";
//         for (int k = 0; k < n; k++) {
//             std::cout << arr[k] << " ";
//         }
//         std::cout << std::endl;
//     }
// }

// int main() {
//     int arr[] = {64, 34, 25, 12, 22, 11, 90};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     std::cout << "Original array: ";
//     for (int i = 0; i < n; i++) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;

//     bubbleSort(arr, n);

//     std::cout << "Sorted array: ";
//     for (int i = 0; i < n; i++) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }
