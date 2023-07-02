// convert temperature in celsius to kelvin.

#include<iostream>
using namespace std;
int main(){
    float cel,kel;
    cout<<"convert temperature celsius to kelvin"<<endl;
    cout<<"input the temperature in the celsius = "<<endl;
    cin>>cel;
    kel=cel + 273.15;
    cout<<"the temperature in celsius = "<<cel<<endl;
    cout<<"the temperature in kelvin = "<<kel<<endl;
return 0;
}