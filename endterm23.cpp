#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int num;
    cin>>num;
    int arr[num];
    if(num>100){
        cout<<"do not do this\n";
    }
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }
    sort(arr,arr+num,greater<int>());
    for(int i=0;i<num;i++){
        if(arr[i]>90){
            cout<<arr[i]<<" ";
        }
    }
return 0;
}