// Derived data type :
// 1. String : 
#include<iostream>
#include<string>
using namespace std;
int main(){
    // string str;                         
    // cin>>str;  --> delimiter : space, enter
    // cout<<str<<endl;
    // string str2 = "hello world";
    // cout<<sizeof(string)<<endl;
    // cout<<sizeof(str2)<<endl;
    // cout<<str2<<endl;

    // Q. why we say string to be not a premitive datatype but an object?
    
    // getline(cin,str);       // delimiter : enter
    // cout<<str<<endl;              

    // Access method from the string class
    // 1. on run-time , you can expand the value of a string --> push_back(char)
    // --> push_back(char) :- appends a character to the string
    // 2. on run-time , you con shrink the value of a string
    // pop_back() :- remove the last character from the string


    // str.push_back('w');
    // cout<<str<<endl;

    // str.pop_back();
    // cout<<str<<endl;

    // object syntax of the string : 
    string s1("this is string one");
    // string s2("this is string two");

    // different ways of concatening strings :
    // way 1 : using '+'
    // string s3=s1+s2;
    // cout<<s3<<endl;

    // s1.append(s2);
    // cout<<s1<<endl;
    // cout<<s2<<endl;

    // strcmp and strcat --> string header file 
    
    // capacity()  -->bytes allocated to store the string ; capacity() < sizeof() < capacity() 
    // cout<<s1.capacity()<<endl;
    // s1.resize(13);
    // new string of the no of character as specified
    // cout<<s1<<endl;
    // cout<<sizeof(s1)<<endl;


    // in c++ string ---> 1. character sequence
    // char str[]={'h','e','l','l','o','\0'} -->'\0'(end of string) -->character sequence
    // 2. string objects --> string methods : 
    // string str("__"); or string str(" ");  <#string>


    // total number of character in given string : here space is counted as one 
    cout<<s1.length()<<endl;

    // cout<<s1<<" "<<s2<<endl;
    // s1.swap(s2);
    // cout<<s1<<" "<<s2<<endl;

// in c/c++/java -->array are static -->does not change the shape, size, and dimension of the array

return 0;
}