#include<iostream>
#include<string>
using namespace std;
class student{
    private:
    string name;
    string regd;
    string street;
    public:
    void get();
    void display();
    student(string name1,string regd1, string street1) : name(name1), regd(regd1), street(street1){}
};
void student::get(){
    cout<<"enter name: ";
    getline(cin,name);
    cout<<"enter registration number : ";
    getline(cin,regd);
    cout<<"enter street: ";
    getline(cin,street);
}
void student::display(){
    cout<<"name : "<<name<<endl;
    cout<<"registration number : "<<regd<<endl;
    cout<<"street : "<<street<<endl;
}
int main(){
    string name,street;
    string regd;
    student madhav(name,regd,street);
    madhav.get();
    madhav.display();
return 0;
}