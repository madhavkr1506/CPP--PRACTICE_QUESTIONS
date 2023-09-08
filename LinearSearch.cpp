#include<iostream>
using namespace std;

bool linearSearch(int n, int arr[], int search) {
    for(int i=0; i < n; i++) {
        if(arr[i] == search) return true;
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
    bool found = linearSearch(n, arr, search);
    // if(found == 0) cout << "FOUND!"; else cout << "NOT FOUND!";
    cout << found << endl;

    return 0;
}