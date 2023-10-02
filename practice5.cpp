#include<iostream>
using namespace std;
class student{
    private:
    char name[100],regd[100],street[100];
    public:
    void get();
    void display();
};
void student::get(){
    cout<<"enter name: ";
    cin>>name;
    cout<<"enter registration number : ";
    cin>>regd;
    cout<<"enter street: ";
    cin>>street;
}
void student::display(){
    cout<<"name : "<<name<<endl;
    cout<<"registration number : "<<regd<<endl;
    cout<<"street : "<<street<<endl;
}
int main(){
    student madhav;
    madhav.get();
    madhav.display();
return 0;
}