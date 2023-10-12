#include<iostream>
using namespace std;
class complex{
    int a;
    int b;
    public:
    void setnumber(int num1,int num2){
        a=num1;
        b=num2;
    }
    void print(){
        cout<<"the sum of the complex number is "<<a<<" + "<<b<<"i"<<endl;
    }
    friend complex sumcomplex(complex o1,complex o2);
};
complex sumcomplex(complex o1,complex o2){
    complex o3;
    o3.setnumber((o1.a + o2.a),(o1.b + o2.b));
    return o3;
}
int main(){
    complex c1,c2,c3;
    c1.setnumber(1,4);
    c1.print();
    c2.setnumber(5,6);
    c2.print();
    c3=sumcomplex(c1,c2);
    c3.print();
return 0;
}