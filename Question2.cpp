// // Binary Search Program in C++ (Recursive)
// #include<iostream>
// using namespace std;

// int binarySearch(int arr[],int first,int last,int x){
//     if(first>=last){
//         int mid = last + (first - last) / 2;
//         if(arr[mid] == x){
//             return mid;
//         }
//         if(arr[mid] > x){
//             return binarySearch(arr,last,mid-1,x);
//         }
//         return binarySearch(arr,mid+1,first,x);
//     }
//     return -1;

// }
// int main(){
//     int n;
//     cout<<"How many elements you want to enter in an array = ";
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cout<<"Enter "<<i<<" element of an array : ";
//         cin>>arr[i];
//     }
//     int search;
//     cout<<"Please enter the elements that you want to search inside the given array : ";
//     cin>>search;
//     int result=binarySearch(arr,0,n-1,search);
//     (result == -1) ? cout<<"Element is not present in the array" : cout<<"Element is present at index "<<result;
// return 0;
// }


// C++ program to implement recursive Binary Search
  
#include <bits/stdc++.h>
using namespace std;
  
// Recursive Binary Search function to find the index of an
// element 'x' in a sorted array 'arr' if elements is
// present, otherwise it return -1
  
// low: The index of the first element in the current
// sub-array high: The index of the last element in the
// current sub-array
int binarySearch(int arr[], int low, int high, int x)
{
    // Base case: If the search space becomes empty, the
    // element is not present in the array
    if (high >= low) {
        // Calculate the middle index to divide the search
        // space in half
        int mid = low + (high - low) / 2;
  
        // If the middle element is equal to 'x', we have
        // found the element, return its index
        if (arr[mid] == x)
            return mid;
  
        // If the middle element is greater than 'x', search
        // in the left half of the array
        if (arr[mid] > x)
            return binarySearch(arr, low, mid - 1, x);
  
        // If the middle element is less than 'x', search in
        // the right half of the array
        return binarySearch(arr, mid + 1, high, x);
    }
  
    // If the base case is reached, the element is not
    // present in the array, return -1
    return -1;
}
  
// Driver code
int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
  
    // Element to be searched
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
  
    return 0;
}