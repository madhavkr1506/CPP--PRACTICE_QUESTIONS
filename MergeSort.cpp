#include<iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end) {
    int n1 = (mid - start) + 1;
    int n2 = end - mid;
    // just for comparisions, we create L and R of size n1 & n2 resp
    int L[n1]; int R[n2];
    // copy all the elements of L & R from the original array 'arr'
    for(int i=0; i < n1; i++)
        L[i] = arr[start + i];
    for(int i=0; i < n2; i++)
        R[i] = arr[(mid+1) + i];
    // Merge the solutions into the original array by comparing the values of L & R
    int i=0; int j=0; int k = start;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) { arr[k] = L[i]; i++; k++; }
        else { arr[k] = R[j]; j++; k++; }
    }
    while(i < n1) { arr[k] = L[i]; i++; k++; }
    while(j < n2) { arr[k] = R[j]; j++; k++; }
}

void mergeSort(int arr[], int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;
        // divide my array into two arrays i.e. 'L' & 'R'
        mergeSort(arr, start, mid);     // L
        mergeSort(arr, mid+1, end);     // R
        merge(arr, start, mid, end);
    }
}

void printArray(int n, int arr[]) {
    for(int i=0 ; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i < n; i++)
        cin >> arr[i];
    printArray(n, arr);
    mergeSort(arr, 0, n-1);
    printArray(n, arr);

    return 0;
}