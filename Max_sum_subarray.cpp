#include<iostream>
using namespace std;

int max_sum_subArray(int n, int arr[], int k) {
    // create the first window and find the sum of the elements in the window.
    // k = 3 | W1 :- index0 - index2
    if(k > n) return -1;
    int maxSum = 0;
    for(int i=0; i < k; i++) {              // 0, 1, 2
        maxSum += arr[i]; 
    }
    // maxSum = 3 + 1 + 4 = 8
    int possibleAns = maxSum;
    for(int i=k; i < n; i++) {
        possibleAns = (possibleAns + arr[i]) - arr[i-k];           // W2 :- 12
        maxSum = max(possibleAns, maxSum);
    }
    return maxSum;
}

int main() {
    int n;
    cin >> n;
    int nums[n];
    for(int i=0; i < n; i++)
        cin >> nums[i];
    int k;
    cin >> k;
    int maxSum = max_sum_subArray(n, nums, k);
    cout << maxSum << endl;

    return 0;
}