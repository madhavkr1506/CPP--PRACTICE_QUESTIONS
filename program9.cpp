#include<iostream>
using namespace std;
class complex{
    int a,b;
    public:
    complex(void);
    void printnumber(){
        cout<<"the number is "<<a<<" + "<<b<<"i"<<endl;
    }
};
complex::complex(void){
    a=10;
    b=20;
}
int main(){
    complex c;
    c.printnumber();

return 0;
}