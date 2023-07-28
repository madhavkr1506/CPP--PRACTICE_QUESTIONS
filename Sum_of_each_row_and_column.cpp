// write c++ program to find sum of each row and columns of a matrix : 
#include<iostream>
#define size 3
using namespace std;
int main(){
    int arr[size][size];
    int row, col, sum=0;

    cout<<"enter elements in matrix of size "<<size<<" x "<<size<<"\n";
    for(row=0;row<size;row++){
        for(col=0;col<size;col++){
            cin>>arr[row][col];
        }
    }

    for(row=0;row<size;row++){
        sum=0;
        for(col=0;col<size;col++){
            sum+=arr[row][col];
        }
        cout<<"sum of elements of row "<<row+1<<" = "<<sum<<"\n";
    }

    for(row=0;row<size;row++){
        sum=0;
        for(col=0;col<size;col++){
            sum+=arr[col][row];
        }
        cout<<"sum of elements of column "<<row+1<<" = "<<sum<<"\n";
    }
return 0;
}