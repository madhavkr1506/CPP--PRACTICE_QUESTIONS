// write c++ program to check two matrices are equal or not : 
#include<iostream>
using namespace std;
#define size 2

int main(){
    int a[size][size];
    int b[size][size];
    int row,col,isequal;

    cout<<"enter elements in matrix a of size "<<size<<" x "<<size<<"\n";
    for(row=0;row<size;row++){
        for(col=0;col<size;col++){
            cin>>a[row][col];
        }
    }

    cout<<"enter elements in matrix b of size "<<size<<" x "<<size<<"\n";
    for(row=0;row<size;row++){
        for(col=0;col<size;col++){
            cin>>b[row][col];
        }
    }

    isequal=1;

    for(row=0;row<size;row++){
        for(col=0;col<size;col++){
            if(a[row][col]!=b[row][col]){
                isequal=0;
                break;
            }
        }
    }
    if(isequal==1){
        cout<<"\nmatrix a is equal to matrix b";
    }
    else{
        cout<<"\nmatrix a is not equal to matrix b";
    }
return 0;
}