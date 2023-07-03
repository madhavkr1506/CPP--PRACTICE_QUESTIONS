// write a c++ program to add two binary numbers.
#include<iostream>
#include<math.h>
using namespace std;
int main(){
    long bn1,bn2;
    int i=0,r=0;
    int sum[20];
    cout<<"additions of two binary numbers"<<endl;
    cout<<"input the first binary numbers = ";
    cin>>bn1;
    cout<<"input the second binary numbers = ";
    cin>>bn2;
    while (bn1 != 0 || bn2 != 0){
        sum[i++] = (int)((bn1 % 10 + bn2 % 10 + r) % 2);
        r = (int)((bn1 % 10 + bn2 % 10 + r) / 2);
        bn1=bn1/10;
        bn2=bn2/10;
    }
    if (r != 0){
        sum[i++] = r;
    }
    --i;
    cout<<"the sum of two binary numbers is = ";
    while (i >= 0){
        cout<<(sum[i--]);
    }
    cout<<endl;
return 0;
}