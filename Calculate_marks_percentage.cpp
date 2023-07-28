// write c++ program to calculate total marks percentage division of student : 
#include<iostream>
#include<string.h>
using namespace std;
int main(){
    int rollno,phy,che,it,total;
    float percentage;
    char name[20],div[10];

    cout<<"input roll number of the student = ";
    cin>>rollno;

    cout<<"input the name of the student  = ";
    cin>>name;

    cout<<"input the marks of physics, chemistry and information technology = ";
    cin>>phy>>che>>it;

    total=phy+che+it;
    percentage=total/3.0;

    if(percentage>=60){
        strcpy(div,"First");
    }
    else if(percentage<60 && percentage>=48){
        strcpy(div,"Second");
    }
    else if(percentage<48 && percentage>=36){
        strcpy(div,"Pass");
    }
    else{
        strcpy(div,"Fail");
    }

    cout<<"roll number : "<<rollno<<endl<<"name of the student : "<<name<<endl;
    cout<<"marks in physics : "<<phy<<endl;
    cout<<"marks in chemistry : "<<che<<endl;
    cout<<"marks in information technology : "<<it<<endl;
    cout<<"total marks : "<<total<<endl;
    cout<<"percentage : "<<percentage<<endl;
    cout<<"division : "<<div<<endl;
return 0;
}