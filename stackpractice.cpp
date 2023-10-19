#include<iostream>
using namespace std;
struct stack{
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
    if(ptr->top ==ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}

int stacktop(struct stack * ptr){
    return ptr->arr[ptr->top];
}

int stackbottom(struct stack * ptr){
    return ptr->arr[0];
}

void push(struct stack * ptr,int data){
    if(isfull(ptr)){
        cout<<"overflow\n";
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=data;
        // cout<<"pushing "<<data<<"\n";
    }
}

int pop(struct stack * ptr){
    if(isempty(ptr)){
        cout<<"underflow\n";
    }
    else{
        int val=ptr->arr[ptr->top];
        // cout<<"pop "<<val<<endl;
        ptr->top--;
        return val;
    }
}

int peek(struct stack * ptr,int i){
    if((ptr->top - i + 1) < 0){
        cout<<"invalid position\n";
        return -1;
    }
    else{
        return ptr->arr[ptr->top - i + 1];
    }
}

void copystack(struct stack * ptr1,struct stack * ptr2){
    while(!isempty(ptr1)){
        int element=pop(ptr1);
        if(element != -1){
            push(ptr2,element);
        }
    }
}
int main(){
    struct stack * s = (struct stack * )malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    struct stack * b = (struct stack * )malloc(sizeof(struct stack));
    b->size = 10;
    b->top = -1;
    b->arr = (int *)malloc(s->size * sizeof(int));
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        int data;
        cin>>data;
        push(s,data);
    }

    for(int j=1;j<=s->top+1;j++){
        cout<<peek(s,j)<<" ";
    }
    cout<<endl;
    // pop(s);
    // for(int j=1;j<=s->top+1;j++){
    //     cout<<peek(s,j)<<" ";
    // }

    copystack(s,b);
    for(int j=1;j<=b->top+1;j++){
        cout<<peek(b,j)<<" ";
    }
return 0;
}