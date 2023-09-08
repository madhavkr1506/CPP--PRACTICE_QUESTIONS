/* Assign and print the roll number, phone number and address of two students having names "sam" and "john"
 respectively by creating two objects of the class "student".
 */
#include<iostream>
using namespace std;
#include<string>
class student{
    private:
    long long phone_number;
    public:
    int roll_number;
    string str1;
    void Details(long long phone_number1);
    void getData(){
        cout<<"Roll_number of the student = "<<roll_number<<endl;
        cout<<"Address of the student = "<<str1<<endl;
        cout<<"Phone number of the student = "<<phone_number<<endl;
    }
};
void student :: Details(long long phone_number1){
    phone_number=phone_number1;
}
int main(){
    student information;
    information.roll_number = 12213356;
    information.str1 = "India";
    information.Details(9693744950);
    information.getData();
return 0;
}
