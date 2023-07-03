// accepts the user's first name and last name and print them in reverse order with a space between them.
#include<iostream>
#include<string>
using namespace std;
int main(){
    char fname[30],lname[30];
    cout<<"print the name in reverse order where last name come first."<<endl;
    cout<<"input first name"<<endl;
    cin>>fname;
    cout<<"input last name"<<endl;
    cin>>lname;
    cout<<"name in reverse order "<<lname<<" "<<fname<<endl;
return 0;
}