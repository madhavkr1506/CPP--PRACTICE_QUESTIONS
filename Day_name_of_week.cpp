// write c++ program to print day name of week :
 #include<iostream>
 using namespace std;
 int main(){
    int week;
    cout<<"enter week number (1-7) : ";
    cin>>week;

    if(week==1){
        cout<<"monday";
    }
    else if(week==2){
        cout<<"tuesday";
    }
    else if(week==3){
        cout<<"wednesday";
    }
    else if(week==4){
        cout<<"thursday";
    }
    else if(week==5){
        cout<<"friday";
    }
    else if(week==6){
        cout<<"saturday";
    }
    else if(week==7){
        cout<<"sunday";
    }
    else{
        cout<<"invalid input";
    }
return 0;
 }