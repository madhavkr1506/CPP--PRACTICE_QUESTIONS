#include<iostream>
using namespace std;
class fruits{
    public:
    int total_fruits;
};
class apples:public fruits{
    public:
    int count_apple;
};
class mangoes:public fruits{
    public:
    int count_mangoes;
};
int main(){
    apples apple;
    apple.count_apple=10;
    mangoes mango;
    mango.count_mangoes=20;
    fruits fruit;
    fruit.total_fruits=apple.count_apple + mango.count_mangoes;
    cout<<apple.count_apple<<endl;
    cout<<mango.count_mangoes<<endl;
    cout<<fruit.total_fruits<<endl;

return 0;
}