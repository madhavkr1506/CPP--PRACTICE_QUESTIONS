// write a c++ program to print a mystery series from 1 to 50.
#include<iostream>
using namespace std;
int main(){
    cout<<"print a mystery series"<<endl;
    cout<<"the series are"<<endl;
    int nm1=1;
    while (true){
        ++nm1;
        if ((nm1 % 3) == 0)
        continue;
        if (nm1 == 50)
        break;
        if((nm1 % 2) == 0){
            nm1 +=3;
        }
        else{
            nm1 -=3;
        }
        cout<<nm1<<" ";
    }
return 0;
}