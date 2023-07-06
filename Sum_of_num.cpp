// write a c++ program that accepts n different numbers(0 to 100) as well as an integer s which is equal to the sum of the n different numbers.
#include<iostream>
#define range(i, a, b) for(int (i)=(a);(i)<(b);(i)++)
#define rep(i,n) range(i, 0, n)
using namespace std;
int n,s;
long long int dp[10][1010];
int main(void){
    dp[0][0]=1LL;
    rep(i,101){
        for(int j = 8; j >= 0; j--)rep(k, 1010){
            if(k + i <= 1010){
                dp[j+1][k+i]+=dp[j][k];
            }
        }
    }
    cout<<"input n and s : ";
    cin>>n>>s;
    cout<<"\nnumber of combination : ";
    cout<<dp[n][s]<<endl;
return 0;
}