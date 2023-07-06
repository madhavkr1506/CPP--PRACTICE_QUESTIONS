// write a c++ program that convert a given number into hours and minutes.
#include<iostream>
#include<string>
using namespace std;
void time_convert(int num){
    bool flag;
    int hr = 0;
    do{
        flag = false;
        if (num >= 60){
            hr++;
            num -= 60;
            flag = true;
        }
    }while (flag);
    cout<<"\nH:M "<<hr<<":"<<num<<endl;
}
int main(){
    time_convert(67);
    time_convert(60);
    time_convert(120);
    time_convert(40);
return 0;
}
