// write a c++ program that check whether two straight lines ab and cd are orthogonal or not : 
#include<iostream>
using namespace std;
int main(void){
    double x[4],y[4];
    while(cin >> x[0] >> y[0]){
        for (int i=1; i<4; i++){
            cin >> x[i] >> y[i];
        }
        if ((x[1]-x[0])*(x[3]-x[2])+(y[3]-y[2])*(y[1]-y[0]) == 0){
            cout<<"yes, ab and cd are orthogonal."<<endl;
        }
        else{
            cout<<"yes, ab and cd are not orthogonal."<<endl;
        }
    }
return 0;
}