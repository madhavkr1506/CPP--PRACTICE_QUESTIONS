// convert temperature in celsius to fahrenheit.

#include<iostream>
using namespace std;
int main(){
    float frh,cel;
    cout<<"convert temperature in celsius to fahrenheit"<<endl;
    cout<<"input the temperature in the celsius = "<<endl;
    cin>>cel;
    frh=(cel * 9.0) / 5.0 + 32;
    cout<<"the temperature in celsius = "<<cel<<endl;
    cout<<"the temperature in fahrenheit = "<<frh<<endl;
return 0;
}