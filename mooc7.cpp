#include<iostream>
using namespace std;
void towerofhanoi(int n,char sender,char destination,char helper){
    if(n == 0){
        return;
    }
    else{
        towerofhanoi(n-1,sender,helper,destination);
        cout<<"moving disc "<<n<<" form "<<sender<<" to "<<destination<<endl;
        towerofhanoi(n-1,helper,destination,sender);
    }
}
int main(){
    int n;
    cin>>n;
    towerofhanoi(n,'a','b','c');
return 0;
}