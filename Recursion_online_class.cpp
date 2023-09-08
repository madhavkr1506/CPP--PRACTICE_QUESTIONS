#include<iostream>
using namespace std;

int fib(int n, int memo[]);

int fib(int n, int memo[]) {
    // the value of fib(n) was calculated before as a intermediate result
    if( memo[n] != -1 ) return memo[n];
    else if( n == 1 ) return 0;
    else if(n == 2) return 1;
    memo[n] = fib(n-1, memo) + fib(n-2, memo);
    return memo[n];
}

int main() {
    int n;
    cin >> n;
    // create a memo for myself -> Responsible for storing intermediate results
    if(n < 0) {
        cout << "Invalid Input" << endl;
    } else {
        int memo[n+1];
        memo[0] = -1;
        memo[1] = 0;
        memo[2] = 1;
        for(int i=3; i <=n; i++) 
            memo[i] = -1;
        int result = fib(n, memo);
        cout << result << endl;
    }
    return 0;
}