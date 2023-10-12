#include<iostream>
using namespace std;
class school{
    int id;
    static int count;
    public:
    void info(void);
    void display(void);
    static void getcount(void){
        cout<<"the count is "<<count<<endl;
    }
};
void school :: info(void){
    cout<<"enter your number\n";
    cin>>id;
    count++;
}
void school :: display(void){
    cout<<"at number "<<count<<" registration id is "<<id<<endl; 
}

int school::count;
int main(){
    school madhav,krishna,shyam;
    madhav.info();
    madhav.display();
    school::getcount();
    krishna.info();
    krishna.display();
    school::getcount();
    shyam.info();
    shyam.display();
    school::getcount();
return 0;
}