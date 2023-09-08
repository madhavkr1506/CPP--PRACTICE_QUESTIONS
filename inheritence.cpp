#include<iostream>
using namespace std;

class Employee {
    protected:
        int empId; string empName; bool isPermanent;
    public:
        Employee() {
            cout << "Object of Employee created..." << endl;
        }
        Employee(int empId, string empName, bool isPermanent) {
            this->empId = empId;
            this->empName = empName;
            this->isPermanent = isPermanent;
        }
        int getEmpId() {return this->empId;}
        string getEmpName() {return this->empName;}
        bool getIsPermanent() {return this->isPermanent;}
        void setEmpId(int newEmpId) { this->empId = newEmpId; } 
        void setEmpName(string newEmpName) { this->empName = newEmpName; } 
        void setIsPermanent(int newIsPermanent) { this->isPermanent = newIsPermanent; } 
        void display() {
            cout << this->empId << " " << this->empName << " " << this->isPermanent << endl;
        }
};

class Developer:public Employee {
    protected:
        int yoe; string techStack; int salary;
    public:
        Developer() {
            cout << "Object of Developer created..." << endl;
        }
        Developer(int empId, string empName, bool isPermanent, int yoe, string techStack, int salary) {
            this->empId = empId;
            this->empName = empName;
            this->isPermanent = isPermanent;
            this->yoe = yoe;
            this->salary = salary;
            this->techStack = techStack;
        }
        void display() {
            cout << this->empId << " " << this->empName << " " << this->isPermanent << this->yoe << " " << this->salary << " " << this->techStack << endl;
        }
};

class Coder:public Developer {
    protected:
        int noOfLang;
    public:
        Coder() {
            cout << "Object of Coder created..." << endl;
        }
        Coder(int empId, string empName, bool isPermanent, int yoe, string techStack, int salary, int noOfLang) {
            this->setEmpId(empId);
            this->setEmpName(empName);
            this->setIsPermanent(isPermanent);
            this->yoe = yoe;
            this->salary = salary;
            this->techStack = techStack;
            this->noOfLang = noOfLang;
        }
        void display() {
            cout << this->empId << " " << this->empName << " " << this->isPermanent << this->yoe << " " << this->salary << " " << this->techStack << this->noOfLang << endl;
        }
};

int main() {
    // Developer dev1(234352, "Developer-1", true, 10, "MERN Stack", 30);
    // dev1.display();

    // Developer dev1(234352, "Developer-1", true, 10, "MERN Stack", 30);
    // dev1.display();

    Coder coder1(234352, "Developer-1", true, 5, "MEAN Stack", 10, 5);  
    coder1.display();  
    return 0;
}