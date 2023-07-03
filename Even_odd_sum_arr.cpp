// write a c++ program to calculate the sum of all even and odd number in an array.

#include<iostream>
using namespace std;
int main(){
    int oddsum=0, evensum=0;
    int i,size;
    cout<<"enter the size of the array = ";
    cin>>size;
    int arr[size];
    cout<<"enter the array elements = "<<endl;
    for(i=0;i<size;i++){
        cin>>arr[i];
    }
    for (i=0;i<size;i++){
        if (arr[i]%2==0){
            evensum=evensum+arr[i];
        }
        else{
            oddsum=oddsum+arr[i];
        }
    }
    cout<<endl;
    cout<<"the sum of odd numbers are = "<<oddsum<<endl;
    cout<<"the sum of even numbers are = "<<evensum<<endl;
return 0;
}
