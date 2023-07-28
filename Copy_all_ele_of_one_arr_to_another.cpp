// write c++ program to copy all elements of one array to another : 
#include<iostream>
#define MAX_SIZE 100
using namespace std;

int main(){
    int first[MAX_SIZE],second[MAX_SIZE];
    int i,num;

    cout<<"enter size of the array = ";
    cin>>num;

    cout<<"enter first elements of the array = ";
    for(i=0;i<num;i++){
        cin>>first[i];
    }

    for(i=0;i<num;i++){
        second[i]=first[i];
    }

    cout<<"elements of the first array = "<<endl;
    for(i=0;i<num;i++){
        cout<<first[i]<<"\t";
    }

    cout<<"\nelements of the second array = \n";
    for(i=0;i<num;i++){
        cout<<second[i]<<"\t";
    }
return 0;
}