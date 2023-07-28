// write c++ program to interchange diagonals of matrix : 
#include<iostream>
using namespace std;
int main(){
    static int array[10][10];
    int i,j,m,n,a;

    cout<<"enter the order of the matrix = \n";
    cin>>m;
    cin>>n;
    if(m==n){
        cout<<"enter the coefficients of the matrix : \n";
        for(i=0;i<m;++i){
            for(j=0;j<n;++j){
                cin>>array[i][j];
            }
        }
        cout<<"the given matrix is\n";
        for(i=0;i<m;++i){
            for(j=0;j<n;++j){
                cout<<" "<<array[i][j];
            }
            cout<<"\n";
        }
        for(i=0;i<m;++i){
            a=array[i][i];
            array[i][i]=array[i][m-i-1];
            array[i][m-i-1]=a;
        }
        cout<<"the matrix after changing the \n";
        cout<<"main diagonal and secondary diagonal\n";

        for(i=0;i<m;++i){
            for(j=0;j<n;++j){
                cout<<" "<<array[i][j];
            }
            cout<<"\n";
        }
    }
    else{
        cout<<"the given order is not square matrix\n";
    }
return 0;
}