// write c++ program to find prime numbers in given range using functions : 
#include<iostream>
using namespace std;

int isPrime(int num);
void printPrimes(int lower,int upper);

int main(){
    int lower,upper;
    cout<<"enter the lower and upper limits of the lists primes : ";
    cin>>lower;
    cin>>upper;

    printPrimes(lower,upper);
return 0;
}

void printPrimes(int lower, int upper){
    cout<<"list of prime numbers between "<<lower<<" and "<<upper<<" are : "<<endl;
    while(lower<=upper){
        if(isPrime(lower)){
            cout<<lower<<endl;
        }
        lower++;
    }
}

int isPrime(int num){
    int i;
    for(i=2;i<=num/2;i++){
        if(num%i==0){
            return 0;
        }
    }
    return 1;
}