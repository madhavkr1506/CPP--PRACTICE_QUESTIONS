#include<iostream>
#include<string>
using namespace std;
class Occurrence{
    public:
    void countOccurrence(string s, char c);
};
void Occurrence :: countOccurrence(string s, char c){
    int count = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]==c){
            count++;
        }
    }
    cout<<count<<endl;
}
int main(){
    string str1;
    cin>>str1;
    char ch;
    cin>>ch;
    Occurrence hello;
    hello.countOccurrence(str1,ch);
return 0;
}