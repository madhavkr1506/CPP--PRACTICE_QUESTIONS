#include<iostream>
using namespace std;
class madhav{
    private:
    int num1;
    int num2;
    int num3;
    public :
    void setvalue(int a,int b,int c){
        num1=a;
        num2=b;
        num3=c;
    }
    int res;
    void si();
    void display();
};
void madhav::si(){
    res=(num1*num2*num3)/100;
}
void madhav::display(){
    cout<<res;
}
int main(){
    madhav m;
    m.setvalue(2000,12,3);
    m.si();
    m.display();
return 0;
}