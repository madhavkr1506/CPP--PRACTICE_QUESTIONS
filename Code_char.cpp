#include<iostream>
using namespace std;
int main(){
    char singh_ch;
    cout<<"print code(ASCII CODE/UNICODE CODE etc) of a given character"<<endl;
    cout<<"input a character = ";
    cin>>singh_ch;
    cout<<"the ASCII value of "<<singh_ch<<" is : "<<(int)singh_ch<<endl;
    cout<<"the character for the ASCII value "<<(int)singh_ch<<" is : "<<(char)((int)singh_ch)<<endl;
return 0;
}