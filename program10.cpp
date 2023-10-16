#include<iostream>
using namespace std;
class complex{
    int a,b;
    public:
    complex(int ,int);
    void printcomplex(){
        cout<<"the number is = "<<a<<" + "<<b<<"i"<<endl;
    }
};
complex::complex(int x,int y){
    a=x;
    b=y;
}
int main(){
    complex a(4,6);
    a.printcomplex();
    complex b=complex(10,11);
    b.printcomplex();
return 0;
}