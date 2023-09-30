#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;
struct stack {
    int size;
    int top;
    int * arr;
};
int isempty(struct stack * ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int isfull(struct stack * ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct stack * ptr, int val){
    if(isfull(ptr)){
        cout<<"stack is in overflow condition\n";
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}
int pop(struct stack * ptr){
    if(isempty(ptr)){
        cout<<"stack is in empty condition\n";
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int peek(struct stack * ptr, int i){
    if((ptr->top - i + 1) < 0){
        cout<<"invallid position\n";
        return -1;
    }
    else{
        return ptr->arr[ptr->top - i + 1];
    }
}
double calaverage(struct stack * ptr){
    int count = 0;
    double sum = 0.0;
    for(int i=0;i<=ptr->top;i++){
        sum+=ptr->arr[i];
        count++;
    }
    return sum/count;
     
}
int main(){
    struct stack * s = (struct stack * )malloc(sizeof(struct stack));
    s->size=5;
    s->top=-1;
    s->arr=(int *)malloc(s->size * sizeof(int));

    push(s,1);
    push(s,2);
    push(s,3);
    // push(s,14);
    // push(s,15);
    pop(s);
    for(int j=1;j<=s->top+1;j++){
        cout<<peek(s,j)<<"\t";
    }
    cout<<endl;
    double average = calaverage(s);
    cout<<setprecision(2)<<average<<endl;
return 0;
}