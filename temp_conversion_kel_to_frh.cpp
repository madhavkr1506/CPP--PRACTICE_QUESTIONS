// convert temperature in kelvin to fahrenheit
#include<iostream>
using namespace std;
int main(){
    float frh,kel;
    cout<<"convert temperature kelvin to fahrenheit"<<endl;
    cout<<"input the temperature in the kelvin = "<<endl;
    cin>>kel;
    frh=(9.0 / 5) * (kel - 273.15) + 32;
    cout<<"the temperature in kelvin = "<<kel<<endl;
    cout<<"the temperature in fahrenheit = "<<frh<<endl;
return 0;
}