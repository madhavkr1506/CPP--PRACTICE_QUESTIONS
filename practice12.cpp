#include<iostream>
#include<string>
using namespace std;
class binary{
    private:
    string s;
    public:
    void read(void);
    void check_bin(void);
    void display(void);
    void ones_complemented(void);
};
void binary :: read(void){
    cout<<"enter binary number = ";
    cin>>s;
}
void binary :: check_bin(void){
    for(int i=0;i<s.length();i++){
        if(s.at(i)!='0' && s.at(i)!='1'){
            cout<<"invalid binary value\n";
            exit(0);
        }
    }
}
void binary :: ones_complemented(void){
    for(int i=0;i<s.length();i++){
        if(s.at(i) == '0'){
            s.at(i) = '1';
        }
        else{
            s.at(i) = '0';
        }
    }
}
void binary :: display(void){
    cout<<"displaying binary value\n";
    for(int i=0;i<s.length();i++){
        cout<<s.at(i);
    }
    cout<<endl;
}

int main(){
    binary s;
    s.read();
    s.display();
    s.check_bin();
    s.ones_complemented();
    s.display();

return 0;
}