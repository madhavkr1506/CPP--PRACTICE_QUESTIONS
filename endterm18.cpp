#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>

using namespace std;
int main(){
    string s[5];
    for(int i=0;i<5;i++){
        cin>>s[i];
    }
    for(int i=0;i<5;i++){
        reverse(s[i].begin(),s[i].end());
        s[i].erase(s[i].find_last_not_of('0') + 1, string::npos);
        cout<<s[i]<<" ";
    }
    // float m=1.54441651484;
    // cout<<fixed<<setprecision(3)<<m<<endl;
    
    
return 0;
}