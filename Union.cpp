// You are using GCC
#include<iostream>
#include<cstring>
using namespace std;
union Customers{
    char name[50];
    int accountNumber;
    float balance;
};
void incrementBalance(Customers& c){
    if(c.balance>1000){
        // cout<<c.balance<<endl;
        c.balance+=100;
        cout<<c.balance<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    if(n<1 || n>20){
        return 0;
    }
    Customers customerData[n];
    for(int i=0;i<n;++i){
        cin>>customerData[i].name;
        cin>>customerData[i].accountNumber;
        cin>>customerData[i].balance;
        incrementBalance(customerData[i]);
    }
    
return 0;
}