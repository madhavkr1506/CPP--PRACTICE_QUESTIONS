#include<iostream>
using namespace std;

class A {
    protected:
        int d1; bool d2;
    public:
        A() {
            cout << "Object of A created..." << endl;
        }
        A(int d1, bool d2) {
            this->d1 = d1;
            this->d2 = d2;
        }
        void display() {
            cout << this->d1 << " " << this->d2 << endl;
        }
};

class B {
    protected:
        float d3; char d4;
    public:
        B() {
            cout << "Object of B created..." << endl;
        }
        B(float d3, char d4) {
            this->d3 = d3;
            this->d4 = d4;
        }
        void display() {
            cout << this->d3 << " " << this->d4 << endl;
        }
};

// Multiple Inh :- One class is inheriting the two independent class altogether
class C: public A, public B {
    protected:
        string d5; int d6;
    public:
        C() {
            cout << "Object of C created...";
        }
        C(int d1, bool d2, float d3, char d4, string d5, int d6) {
            this->d1 = d1;
            this->d2 = d2;
            this->d3 = d3;
            this->d4 = d4;
            this->d5 = d5;
            this->d6 = d6;
        }
        void display() {
            cout << this->d1 << " " << this->d2 << " " << this->d3 << " " << this->d4 << " " << this->d5 << " " << this->d6 << endl;
        }
};

int main() {
    C objC(100, true, 3.14, 'a', "Hello World", 10000);
    // O/P :- The display() of the child class will be called but not from A & B(parents)
    objC.display();        // which display will be called? -> display(): A | display():B

    // Q:- what if i wanted to call the functions from the parent classes (A or B)?
    // A:- Scope Resolutor ( :: )
    objC.A::display();
    objC.B::display();
    return 0;
}