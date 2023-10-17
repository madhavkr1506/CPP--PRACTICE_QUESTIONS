#include<iostream>
using namespace std;
void towerofhanoi(int n,char traveler,char desttravel,char helper){
    if(n == 0){
        return;
    }
    else{
        towerofhanoi(n - 1,traveler,helper,desttravel);
        cout<<"move disk "<<n<<" from disc "<<traveler<<"to"<<"the road = "<<desttravel<<endl;
        towerofhanoi(n - 1,helper,desttravel,traveler);
    }
}
int main(){
    int n;
    cin>>n;
    towerofhanoi(n,'A','B','C');
return 0;
}