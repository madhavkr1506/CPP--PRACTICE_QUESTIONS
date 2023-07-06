// write a c++ program to add all the numbers from from 1 to given numbers.
#include<iostream>
using namespace std;
int add_1_to_goven_number(int n){
    int total = 0;
    for (int x = 1; x <= n; x++){
        total += x;
    }
    return total;
}
int main(){
    cout<<"\nadd 1 to 4 : "<<add_1_to_goven_number(4);
    cout<<"\nadd 1 to 100 : "<<add_1_to_goven_number(100);
return 0;
}