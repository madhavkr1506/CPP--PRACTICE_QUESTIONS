#include<iostream>
using namespace std;
class shape{
    public:
    shape(){
        cout<<"this is a shape\n";
    }
};
class polygon : public shape{
    public:
    polygon(){
        cout<<"polygon is the shape\n";
    }
};
class rectangle : public polygon{
    public:
    rectangle(){
        cout<<"rectangle is a polygon\n";
    }
};
class triangle : public polygon{
    public:
    triangle(){
        cout<<"triangle is a polygon\n";
    }
};
class square : public rectangle{
    public:
    square(){
        cout<<"square is a rectangle\n";
    }
};
int main(){
    shape sh;
    polygon poly;
    rectangle rec;
    triangle tri;
    square sq;

return 0;
}