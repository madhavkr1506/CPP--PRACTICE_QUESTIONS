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
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return false;
    }
}

int stacktop(struct stack * ptr){
    return ptr->arr[ptr->top];
}

int stackbottom(struct stack * ptr){
    return ptr->arr[0];
}

void push(struct stack * ptr,int val){
    if(isfull(ptr)){
        cout<<"overflow condition"<<endl;
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
        cout<<"element "<<val<<endl;
    }
}

int pop(struct stack * ptr){
    if(isempty(ptr)){
        cout<<"underflow condition\n";
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack * ptr, int i){
    if((ptr->top - i +1) < 0){
        cout<<"invalid position\n";
    }
    else{
        return ptr->arr[ptr->top - i + 1];
    }
}

void bubblesort(struct stack * ptr){
    if(ptr == NULL){
        return;
    }
    int n=ptr->top + 1;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n - i - 1;j++){
            if(ptr->arr[j] > ptr->arr[j +1]){
                swap(ptr->arr[j],ptr->arr[j + 1]);
            }
        }
    }
}
int main(){
    struct stack * s = (struct stack *)malloc(sizeof(struct stack));
    s->size=10;
    s->top=-1;
    s->arr=(int *)malloc(s->size * sizeof(int));
    push(s,111);
    push(s,120);
    push(s,101);
    push(s,92);
    push(s,100);
    push(s,102);
    push(s,101);
    push(s,120);
    push(s,111);
    push(s,125);
    for(int j = 1;j<=s->top + 1;j++){
        cout<<peek(s,j)<<" ";
    }
    cout<<endl;
    bubblesort(s);
    // pop(s);
    for(int j = 1;j<=s->top + 1;j++){
        cout<<peek(s,j)<<" ";
    }
    cout<<endl;
    for(int j = s->top + 1;j>0;j--){
        cout<<peek(s,j)<<" ";
    }
return 0;
}