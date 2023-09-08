#include<iostream>
using namespace std;

int search(int n, int nums[], int target, bool firstOccurance) {
    int resultIndex = -1; int start = 0; int end = n-1;
    while(start <= end) {
        int mid = (start + end) / 2;
        if(target < nums[mid]) end = mid-1;
        else if(target > nums[mid]) start = mid + 1;
        else {
            // resultIndex = 1; start = 0, end = 0
            resultIndex = mid;
            if(firstOccurance) end = mid-1;
            else start = mid+1;
        }
    }
    return resultIndex;
}

int main() {
    int n;
    cin >> n;
    int nums[n];
    for(int i=0; i < n; i++)
        cin >> nums[i];
    int target;
    cin >> target;
    int result[2];
    result[0] = -1; result[1] = -1;
    // Find the values for result[0] & result[1]
    result[0] = search(n, nums, target, true);
    if(result[0] != -1)
        result[1] = search(n, nums, target, false);
    cout << result[0] << " " << result[1] << endl;

    return 0;
}