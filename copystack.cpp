#include<iostream>
#include<stdlib.h>
using namespace std;
struct stack {
    int size;
    int top;
    int *arr;
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
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct stack * ptr, int val){
    if(isfull(ptr)){
        cout<<"stack overflow\n";
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}
int pop(struct stack * ptr){
    if(isempty(ptr)){
        cout<<"stack is in underflow"<<endl;
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int peek(struct stack * ptr,int i){
    if((ptr->top - i + 1 ) < 0){
        cout<<"not a valid position\n";
        return -1;
    }
    else{
        return ptr->arr[ptr->top - i + 1];
    }
}
void copystack(struct stack * ptr,struct stack * ptr2){
    while(!isempty(ptr)){
        int element=pop(ptr);
        if(element != -1){
            push(ptr2,element);
        }
    }
}
int main(){
    struct stack * s = (struct stack *)malloc(sizeof(struct stack));
    s->size=5;
    s->top=-1;
    s->arr=(int *)malloc(s->size * sizeof(int));
    struct stack * b = (struct stack *)malloc(sizeof(struct stack));
    b->size=5;
    b->top=-1;
    b->arr=(int *)malloc(s->size * sizeof(int));

    push(s,11);
    push(s,12);
    push(s,13);
    push(s,14);
    push(s,15);
    for(int j=1;j<=s->top+1;j++){
        cout<<peek(s,j)<<"\t";
    }
    cout<<endl;
    // for(int j=s->top+1;j>=1;j--){
    //     cout<<peek(s,j)<<"\t";
    // }
    copystack(s,b);
    for(int j=1;j<=b->top+1;j++){
        cout<<peek(b,j)<<"\t";
    }

return 0;
}