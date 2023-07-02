// write a c++ program to display the current date and time.
#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;
int main(){
    time_t t = time(NULL);
    tm* tptr = localtime(&t);
    cout<<"display the current date and time"<<endl;
    cout<<"seconds = "<<(tptr->tm_sec)<<endl;
    cout<<"minutes = "<<(tptr->tm_min)<<endl;
    cout<<"hours = "<<(tptr->tm_hour)<<endl;
    cout<<"day of month = "<<(tptr->tm_mday)<<endl;
    cout<<"month of year = "<<(tptr->tm_mon)+1<<endl;
    cout<<"year = "<<(tptr->tm_year)+1900<<endl;
    cout<<"weekday = "<<(tptr->tm_wday)<<endl;
    cout<<"day of year = "<<(tptr->tm_yday)<<endl;
    cout<<"daylight savings = "<<(tptr->tm_isdst)<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"current date = "<<(tptr->tm_mday)<<"/"<<(tptr->tm_mon)+1<<"/"<<(tptr->tm_year)+1900<<endl;
    cout<<"current time = "<<(tptr->tm_hour)<<":"<<(tptr->tm_min)<<":"<<(tptr->tm_sec)<<endl;
return 0;
}