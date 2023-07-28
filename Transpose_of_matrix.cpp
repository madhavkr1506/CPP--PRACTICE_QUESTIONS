// write c++ program to find transpose of a matrix :
#include<iostream>
using namespace std;
int main(){
    static int array[10][10];
    int i,j,m,n;
    cout<<"enter the order of the matrix\n";
    cin>>m>>n;
    cout<<"enter the coefficients of the matrix\n";
    for(i=0;i<m;++i){
        for(j=0;j<n;++j){
            cin>>array[i][j];
        }
    }
    
    for(i=0;i<m;++i){
        for(j=0;j<n;++j){
            cout<<" "<<array[i][j];
        }
        cout<<"\n";
    }

    cout<<"transpose of the matrix\n";
    for(j=0;j<n;++j){
        for(i=0;i<m;++i){
            cout<<" "<<array[i][j];
        }
        cout<<"\n";
    }
return 0;
}