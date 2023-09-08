#include<iostream>
using namespace std;

// 4 PILLARS OF OOPs

// 1. Encapsulation :- Clubbing the data-members, member functions & constructors all together into one single unit called class. 
// 2. Abstraction :- A way of hiding implementation details from the user & show only the necessary details relevant to the user. [ Access Modifier ]
// 3. Polymorphism :- Poly (many) + Morph (form) :- A member function in a class which has same name but different functionalities.
// -> Types :- Complie Time :- i.) Function Overloading (same fn name; diff params) | ii.) Operator Overloading
//             Run Time :- i.) virutual functions |

class Bank {
    private:
        int principal; float rate; int years; string acc_type; bool is_matured;
    public:
        Bank(int principal, float rate, int years, string acc_type, bool is_matured) {
            this->principal = principal;
            this->rate = rate;
            this->years = years;
            this->acc_type = acc_type;
            this->is_matured = is_matured;
        }
        void display() {
            cout << this->principal << " " << this->rate << " " << this->years << " " << this->acc_type << " " << this-is_matured << endl;
        }
        float calculateInterest(int p, float r, int t) {
            return (p * r * t) / 100; 
        }
        float calculateInterest(int p, int t, float r) {
            return (p * r * t) / 200; 
        }
};

// Function Overloading to happen following of the 3 conditions should be satisfied -
// i.) No of params change
// ii.) Type of the params
// iii.) Order of the params 
// NOTE:- return type of any overloaded function is never kept as a part of function overloading.

int main() {
    Bank b1(1200, 3.8, 2, "Savings", false);
    cout << b1.calculateInterest(1200, 2, 3.8) << endl;
    cout << b1.calculateInterest(1200, 3.8, 2) << endl;
    return 0;
}