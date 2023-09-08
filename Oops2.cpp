#include<iostream>
using namespace std;

// Class :- created outside the main method :- A class is a template describing what different type of data & functions one object can bear.
class Demo {
    private:        // data-member & member-functions can ONLY be used inside the class
        // data | data-member
        // If the data-member is not initalised, it gets initialised w garbage values;
        int data1; string data2; bool data3; float data4;

    public:         // data-member & member-functions can be used inside AND outside the class
        // GETTERS (read the data-member) & SETTERS (set / change the data-members) :-
        int getData1() { return data1; }
        void setData1(int updatedData1) { data1 = updatedData1; }
        string getData2() { return data2; }
        void setData2(string updatedData2) { data2 = updatedData2; }
        bool getData3() { return data3; }
        void setData3(bool updatedData3) { data3 = updatedData3; }
        float getData4() { return data4; }
        void setData4(float updatedData4) { data4 = updatedData4; }

        // functions | member-functions
        void display() {
            cout << data1 << " " << data2 << " " << data3 << " " << data4 << endl;
        }
};


// ACCESS MODFIER :- private(default), public(to access members outside the class using an object), protected 
int main() {

    // Object of a class :- Real-Life Entit built out of the class
    // Syntax :- ClassName objectName;
    Demo demoObj;
    demoObj.setData1(100);                      // demoObj.data1 = random
    demoObj.setData2("My_Demo_Object_1");
    demoObj.setData3(false);
    demoObj.setData4(3.14);
    demoObj.display();

    return 0;
}