// write c++ program to multiply two matrices : 
#include<iostream>
using namespace std;
int main(){
    int a[10][10],b[10][10],res[10][10],r1,c1,r2,c2,i,j,k;

    cout<<"enter rows and column for first matrix : ";
    cin>>r1;
    cin>>c1;

    cout<<"enter rows and column for second matrix : ";
    cin>>r2;
    cin>>c2;

    while(c1!=r2){
        cout<<"error! column of first matrix not equal to row of second matrix.\n\n";
        cout<<"enter rows and columns for first matrix : ";
        cin>>r1;
        cin>>c1;
        cout<<"enter rows and columns for second matrix : ";
        cin>>r2;
        cin>>c2;
    }
    cout<<"enter elements of matrix 1  : \n";
    for(i=0;i<r1;++i)
    for(j=0;j<c1;++j){
        cout<<"enter elements a"<<i+1<<j+1<<" : ";
        cin>>a[i][j];
    }

    cout<<"enter elements of matrix 2  : \n";
    for(i=0;i<r2;++i)
    for(j=0;j<c2;++j){
        cout<<"enter elements b"<<i+1<<j+1<<" : ";
        cin>>b[i][j];
    }    

    for(i=0;i<r1;++i)
    for(j=0;j<c2;++j){
        res[i][j]=0;
    }

    for(i=0;i<r1;++i)
    for(j=0;j<c2;++j)
    for(k=0;k<c1;++k){
        res[i][j]+=a[i][k]*b[k][j];
    }

    cout<<"\noutput matrix : \n";
    for(i=0;i<r1;++i)
    for(j=0;j<c2;++j){
        cout<<" "<<res[i][j];
            if(j==c2-1)
        cout<<"\n\n";
    }
return 0;
}