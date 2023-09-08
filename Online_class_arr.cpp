#include<iostream>
using namespace std;

// 2. Array in c++ : 
// Array is a collection of similar types od DTs.
// A complex variable is capable of storing multiple values in a single variable.
// Datatype variableName = variableValue;
int main(){


// Syntax 1 : dataType arrayName[size];
// int arr[5];                 // index  :- 0, 1, 2, 3, 4.... 
// indices :- start = 0; end = size - 1
// array in c++ are created over contiguous memory.
// each element is stored right next to each other.
// arr[0] = 100;
// arr[1] = 200;
// arr[2] = 300;
// arr[3] = 400;
// arr[4] = 500;
// cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<" "<<arr[4]<<endl;
// cout<<arr<<endl;   //0x61feec (address)
// if you cannot have an idea on the size, you had hard-code the values
// string arr2[]={"This","is","a","string"};
// cout<<arr2[0]<<" "<<arr2[1]<<" "<<arr2[2]<<" "<<arr2[3]<<endl;
// Size of the array : 
// cout<<"the size of the array = "<<sizeof(arr)<<endl;     // 20 ->5 * sizeof(arr)
// cout<<"the size of the array = "<<sizeof(arr2)<<endl;    // 24 * 4 = 96

// Intersted to find the size of the array : 
// cout<<"No of elements in arr array - "<<sizeof(arr) / sizeof(int)<<endl;
// cout<<"No of elements in arr2 array - "<<sizeof(arr2) / sizeof(string)<<endl;

// Loops :- for, while, do-while
// starting-point ; ending-point(condition); inc/dec.

// 1. for-loop
// q:- If i have to create an infinite for-loop....?
// for(;;){ }

// for(start; end-point; inc/dec)
// pre-increment --> ++i
// post-increment --> i++
// int i=1;
// for(i=1;i<=5;i++){
//     cout<<i<<" ";
// }
// cout<<endl;
// cout<<"the last updated value for post incremented is : "<<i<<endl;
// cout<<endl;
// int j=0;
// for(j=0;j<5;++j){
//     cout<<j<<" ";
// }
// cout<<endl;
// cout<<"the last updated value for pre incremented is : "<<j<<endl;

// int a=10;
// int b=21;
// cout<<a++ + ++b;
// cout<<endl;
// cout<<a<<" "<<b<<endl;
// for(int i=2;i<21;i=i+2){
//     cout<<i<<" ";
// }
// cout<<endl;


// table of 2 - [ 2 - 20 ] -> [2 x 1 = 2; 2 x 10 = 20] 
// for (int i=2;i<=20;i+=2){
//     cout<<i<<" ";
// }
// cout<<endl;

// for (int i=1;i<=10;i+=1){
//     cout<<i*2<<" ";
// }
// cout<<endl;


// 2. wHILE LOOP => entry control loop
// Q: keep asking for a value from the user, until he does not input 0

// initial _declaration
// while (condition){....  }
// int n;
// cin>>n;
// int i = n;
// while(i!=n*11){
//     cout<<n<<" x "<<i/n<<" = "<<i<<endl;
//     i=i+n;
// }

// int n=1;
// while(n!=0){
//     cin>>n;
// }

// for(int i=1;i!=0;i+=1){
//     cout<<i<<endl;
//     cin>>i;
// }

// int n;
// for(int i=0;i<INT_MAX;i++){
//     cin>>n;
//     if(n==0) break;
//     continue;
// }

// 3. do-while loop => exit control loop
// int n=0;
// do{
//     cin>>n;
// }while(n!=0);

// int n=0;while(n!=0){
//     cin>>n;
// }

// 4. foreach loop => only used in arrays
// int n;
// cin>>n;
// int myArr[n];
// for(int i=0;i<n;i++){
//     cin>>myArr[i];
// } 
// for(int i=0;i<n;i++){
//     cout<<myArr[i]<<" ";
// } 
// cout<<endl;

// int arr1[]={1,2,3,4,5};
// for(int x: arr1){
//     cout<<x<<" ";
// }
// cout<<endl;
return 0;
}