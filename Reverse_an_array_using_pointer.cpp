// write c++ program to print elements of an array in reverse order using pointer :
#include<iostream>
using namespace std;
int main(){
    int arr[5],i;
    int *p=arr;
    cout<<"enter five numbers separated by space : ";
    cin>>*p>>*(p+1)>>*(p+2)>>*(p+3)>>*(p+4);
    cout<<"your entered number in reverse order are = \n";
    for(i=4;i>=0;i--){
        cout<<*(p+i)<<endl;
    }
return 0;
}