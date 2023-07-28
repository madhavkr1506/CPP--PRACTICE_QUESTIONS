// write c++ program to count even and odd elements : 
#include<iostream>
#define MAX_SIZE 100
using namespace std;
int main(){
    int arr[MAX_SIZE];
    int i,num,evennum,oddnum;
    cout<<"enter size of the array : ";
    cin>>num;
    cout<<"enter "<<num<<" elements in array : ";
    for(i=0;i<num;i++){
        cin>>arr[i];
    }
    evennum=0;
    oddnum=0;
    for(i=0;i<num;i++){
        if(arr[i]%2==0){
            evennum++;
        }
        else{
            oddnum++;
        }
    }
    cout<<"total even numbers : "<<evennum<<endl;
    cout<<"total odd numbers : "<<oddnum<<endl;
return 0;
}