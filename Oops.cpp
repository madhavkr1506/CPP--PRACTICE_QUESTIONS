#include<iostream>
using namespace std;
class Operation{
    private:
    int a,b;
    public:

    void add(int a,int b);
    void diff(int a, int b);
    void multi(int a, int b);
    void divi(int a, int b);
    void modu(int a, int b);
};
void Operation :: add(int a, int b){
    
    cout<<"Addition of two numbers: "<<a+b<<endl;
}
void Operation :: diff(int a, int b){
    cout<<"Difference of two numbers: "<<a-b<<endl;
}
void Operation :: multi(int a, int b){
    
    cout<<"Product of two numbers: "<<a*b<<endl;
}
void Operation :: divi(int a, int b){
    if(a==0||b==0){
        cout<<"Division by zero not possible"<<endl;
    }
    else{
        cout<<"Division of two numbers: "<<a/b<<endl;
    }
}
void Operation :: modu(int a, int b){
    if(a==0||b==0){
        cout<<"Division by zero not possible"<<endl;
    }
    else{
        cout<<"Modulus of two numbers: "<<a%b<<endl;
    }
}
int main(){
    int num1,num2;
    cin>>num1>>num2;
    Operation number;
    number.add(num1,num2);
    number.diff(num1,num2);
    number.multi(num1,num2);
    number.divi(num1,num2);
    number.modu(num1,num2);
return 0;
}