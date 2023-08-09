#include<iostream>
using namespace std;
class AddAmount{
  public:
  void amount(int b);
};
void AddAmount :: amount( int b){
    int total;
    int a=50;
    total=a+b;
    cout<<total<<endl;
}
int main(){
    int num1;
    cin>>num1;
    AddAmount madhav;
    madhav.amount(num1);
return 0;
}