#include<iostream>
using namespace std;

int main() {
    // Array :- contain multiple elements, elements are of the same type
    // int arr[] = {10, 20, 30, 40, 50, 60};
    // arr[0] = 100;

    // Structure :- contain multiple elements, different types of data
    // struct structureName { ... };
    // DDT :- string, arrays, structure
    // Structure a non-primitive DT / Derived Data Types
    // wgich helps you contain a variable - which can store data as well functions in it.
    // Structures aren't a good memory optimsed data types.

    // NOTE:- The total size of the structure will depend upon the no of variables & functions. 
    // Also the amount of space taken by individual data or function.

    // typedef struct students {
    //     // Data - different type
    //     int rno;                                    // 4 bytes
    //     string name;                                // 24 bytes
    //     bool isGraduated;                           // 1 byte
    //     string standard;                            // 24 bytes
    //     int marks[5];                               // 20 bytes
    //     // Functions
    //     void print() {
    //         cout << rno << name << endl;
    //     }
    // }student;

    // create a reference for the structure
    // struct student structureReference
    // struct student student1;
    // // Accessing values from the refence
    // student1.name = "Student One";
    // student1.isGraduated = 0;
    // student1.standard = "10th";
    // student1.rno = 132534;
    // cout << "hello, my name is " << student1.name << ", my rno is " << student1.rno << endl;
    // student1.print();
    // cout << sizeof(student1) << endl;


    // dataType varaible;
    // nameOfStructure referenceOfStructure
    // int a;
    // student studentRef;
    // studentRef.rno = 24352;


    // UNIONS :-
    // Note :- In union, the memory is shared between all the data types;
    union loan {
        int landProperty;           // 4
        char netBanking;            // 1
        char promoCode;             // 1
        float cashAmount;           // 4
        int marks[5];               // 20
    };

    cout << sizeof(loan) << endl;

    // Reference for union
    union loan loan1;
    loan1.netBanking = 'C';
    cout << loan1.netBanking << endl;           // 'C'
    cout << loan1.marks[0] << endl;
    loan1.marks[0] = 92;
    cout << loan1.marks[0] << endl;
    cout << loan1.netBanking << endl;           // Garbage Value
    loan1.netBanking = 'Z';
    cout << loan1.netBanking << endl;           // 'Z'
    loan1.marks[1] = 67;
    loan1.netBanking = 'B';
    cout << loan1.marks[0] << endl;             // 92
    cout << loan1.netBanking << endl;           // Garbage Value

    return 0;
}