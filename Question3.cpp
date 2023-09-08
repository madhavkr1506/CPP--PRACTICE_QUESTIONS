#include<iostream>
using namespace std;

int binarySearch(int n, int arr[], int search,bool firstoccurence) {
    int start = 0; int end = n-1;
    while(start <= end) {
        int mid = (start + end) / 2;
        if(arr[mid] == search) return mid;
        else if(arr[mid] < search) start = mid + 1;
        else end = mid - 1;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i < n; i++)
        cin >> arr[i];
    int search;
    cin >> search;
    // bool found = binarySearch(n, arr, search);
    // cout << found << endl;
    int result[2];
    result[0] = -1; result[1] = -1;
    result[0]=binarySearch(n,arr,search,true);
    if(result[0] != -1){
        result[1]=binarySearch(n,arr,search,false);
    }
    cout<<result[0]<<" "<<result[1]<<endl;

return 0;
}