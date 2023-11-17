#include<iostream>
using namespace std;
class madhav{
    private :
    int num1,num2;
    public :
    int a;
    int b;
    int res;
    void sum();
    void display();
};
void madhav::sum(){
    res=a+b;
}
void madhav::display(){
    cout<<res<<" ";
}
int main(){
    madhav obj;
    obj.a=2;
    obj.b=3;
    obj.sum();
    obj.display();
return 0;
}