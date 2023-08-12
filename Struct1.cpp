#include<iostream>
#include<iomanip>
#include<ctime>
using namespace std;
struct Time {
    int hours;
    int minutes;
    int seconds;
};
void calcDifference(const Time& t1, const Time& t2, Time& result){
    int t1_seconds=t1.hours*3600 + t1.minutes*60 + t1.seconds;
    int t2_seconds=t2.hours*3600+t2.minutes*60+t2.seconds;
    
    int diff_seconds=t1_seconds-t2_seconds;
    if(diff_seconds<0){
        diff_seconds+=24*3600;
    }
    // int diff_seconds=t1_seconds-t2_seconds;
    result.hours=diff_seconds/3600;
    diff_seconds%=3600;
    result.minutes=diff_seconds/60;
    result.seconds=diff_seconds%60;
}

int main(){
    Time start_time, finish_time, duration;
    
    cin>>start_time.hours;
    cin.ignore();
    cin>>start_time.minutes;
    cin.ignore();
    cin>>start_time.seconds;
    cin>>finish_time.hours;
    cin.ignore();
    cin>>finish_time.minutes;
    cin.ignore();
    cin>>finish_time.seconds;
    
    calcDifference(start_time,finish_time,duration);
    
    cout<<setw(2)<<setfill('0')<<duration.hours<<":"<<setw(2)<<setfill('0')<<duration.minutes<<":"
    <<setw(2)<<setfill('0')<<duration.seconds<<endl;
return 0;
}