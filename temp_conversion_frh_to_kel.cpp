// convert temperature in fahrenheit to kelvin.

#include<iostream>
using namespace std;
int main(){
    float frh,kel;
    cout<<"convert temperature fahrenheit to kelvin"<<endl;
    cout<<"input the temperature in the fahrenheit = "<<endl;
    cin>>frh;
    kel=(5.0 / 9) * (frh - 32) + 273.15;
    cout<<"the temperature in fahrenheit = "<<frh<<endl;
    cout<<"the temperature in kelvin = "<<kel<<endl;
return 0;
}