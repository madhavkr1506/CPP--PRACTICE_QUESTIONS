#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
void encryption(const string & inputfile, const string & outputfile){
    ifstream read(inputfile);
    ofstream write(outputfile);
    if(read.is_open() && write.is_open()){
        char ch;
        while(read.get(ch)){
            ch++;
            write.put(ch);
        }
        read.close();
        write.close();
        cout<<"encryption successfully\n";
    }
    else{
        cout<<"failed to open the file\n";
    }
}
void decryption(const string & inputfile, const string & outputfile){
    ifstream read(inputfile);
    ofstream write(outputfile);
    if(read.is_open() && write.is_open()){
        char ch;
        while(read.get(ch)){
            ch--;
            write.put(ch);
        }
        read.close();
        write.close();
        cout<<"decryption successfully\n";
    }
    else{
        cout<<"failed to open the file\n";
    }
}
int main(){
    ofstream write;
    write.open("file1.txt");
    write<<"\nthis is just for showing\n";
    write.close();

    ifstream read;
    read.open("file1.txt");
    while(read.eof()==0){
        string input;
        getline(read,input);
        cout<<input<<endl;
    }
    read.close();

    string inputfile="file1.txt";
    string outputfile="encrypted.txt";
    string thirdfile="decrypted.txt";

    encryption(inputfile,outputfile);

    ifstream readencrypted;
    readencrypted.open("encrypted.txt");
    while(readencrypted.eof()==0){
        string input;
        getline(readencrypted,input);
        cout<<input<<endl;
    }

    decryption(outputfile,thirdfile);
    
    ifstream read_decrypted;
    read_decrypted.open("decrypted.txt");
    while(read_decrypted.eof()==0){
        string input;
        getline(read_decrypted,input);
        cout<<input<<endl;
    }

return 0;
}