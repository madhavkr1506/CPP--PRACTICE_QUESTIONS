#include<iostream>
using namespace std;

void print(void* ptr, char ch);

void print(void* ptr, char ch) {
    if( ch == 'x' ) cout << *((int*) ptr) << endl;
    else if( ch == 'y' ) cout << *((char*) ptr) << endl;
    // else if( ch == 'z' ) cout << *((int*)(((char*)ptr))) << endl;
    else if( ch == 'z' ) cout << (int)*((char*) ptr) << endl;
    else cout << "Invalid";
}

int main() {
    int number = 10;
    char alpha1 = 'x';
    char alpha2 = 'y';
    char alpha3 = 'z';
    // print(&x, 'x')
    print(&number, alpha1);             // 10
    print(&alpha1, alpha2);             // x
    print(&alpha3, alpha3);             // 122

    // Pointers :- a variable which store memory address inside it.
    // Variable :- a memory space / container which stores values in it.
    // int n = 100;
    // cout << n << endl;
    // // print the address of any variable
    // cout << "Memory address of n is : " << &n << endl;

    // // de-structure / de-reference / access the value from a address
    // // type* pointerName = &variable
    // int* memoN = &n;

    // // NOTE:- The type of the pointer depends on the data-type of the value stored.
    // cout << memoN << endl;

    // // type* -> About to store a address | int*, char*, float*

    // // to access the value from the pointer -> use *
    // // Value -> *pointerName
    // cout << "Value kept at " << memoN << " : " << *memoN << endl;
    // cout << "Address of the pointer - " << &memoN << endl;

    // VOID POINTER - Exceptions
    // void* voidP;

    // int* pX; char* pCh; float* pF;
    // int x = 100;
    // char ch = 'a';
    // float f = 3.14;

    // pX = &x;
    // pCh = &ch;
    // pF = &f;

    // voidP = &x;
    // voidP = &ch;
    // voidP = &f;


    return 0;
}