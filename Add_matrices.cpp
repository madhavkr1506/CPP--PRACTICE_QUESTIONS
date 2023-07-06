// how to add two matrices in c++ program :
#include<iostream>
using namespace std;
int main(){
    int r, c, a[100][100], b[100][100], sum[100][100], i, j;
    cout<<"enter numbers in row (between 1 to 100) = ";
    cin>>r;
    cout<<"enter numbers in column (between 1 to 100) = ";
    cin>>c;
    cout<<"\n enter elements of first matric : \n";
    for (i=0;i<r;++i)
    for (j=0;j<c;++j){
        cout<<"enter element a "<<i+1<<j+1<<" : ";
        cin>>a[i][j];
    }
    cout<<"\n enter elements of second matric : \n";
    for (i=0;i<r;++i)
    for (j=0;j<c;++j){
        cout<<"enter element a "<<i+1<<j+1<<" : ";
        cin>>b[i][j];
    }
    for (i=0;i<r;++i)
    for (j=0;j<c;++j){
        sum[i][j]=a[i][j]+b[i][j];
    }
    cout<<"sum of two matrix is  : \n\n";
    for (i=0;i<r;++i)
    for (j=0;j<c;++j){
        cout<<"\t"<<sum[i][j];
        if (j==c-1){
            cout<<"\n\n";
        }
    }
return 0;
}