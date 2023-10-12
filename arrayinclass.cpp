#include<iostream>
using namespace std;

class school{
    private:
    int numofstucdent[100];
    int classroom[100];
    int counter;
    public:
    void initcounter(void) { counter = 0; }
    void student(void);
    void display(void);
};
void school :: student(void){
    cout<<"enter the number of student "<<endl;
    cin>>numofstucdent[counter];
    cout<<"enter classes of student \n";
    cin>>classroom[counter];
    counter++;
}
void school :: display(void){
    for(int i=0;i<counter;i++){
        cout<<"total number of present student in "<<classroom[i]<<" is "<<numofstucdent[i]<<endl;
    }
}
int main(){
    school vidyamandir;
    vidyamandir.initcounter();
    vidyamandir.student();
    vidyamandir.student();
    vidyamandir.display();
return 0;
}