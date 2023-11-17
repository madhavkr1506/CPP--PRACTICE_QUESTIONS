#include<iostream>
using namespace std;
class mammals{
    public:
    void print(){
        cout<<"i am mammle\n";
    }    
};
class marineanimal{
    public:
    void print(){
        cout<<"i am a marine animal"<<endl;
    }
};
class bluewhale: public mammals, public marineanimal{
    public:
    void print(){
        cout<<"i belong to both categories: mammal as well as marine animal\n";
    }
};
int main(){
    mammals animal1;
    animal1.print();
    marineanimal animal2;
    animal2.print();
    bluewhale animal3;
    animal3.print();
    animal3.mammals::print();
    animal3.marineanimal::print();
return 0;
}
