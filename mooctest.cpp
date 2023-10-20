#include<iostream>
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
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct stack * ptr,int value){
    if(!isfull(ptr)){
        ptr->top++;
        ptr->arr[ptr->top]=value;
        cout<<"Element "<<value<<" is pushed onto the stack.\n";
    }
}
int pop(struct stack * ptr){
    if(isempty(ptr)){
        cout<<"stack is underflow cannot perform pop operation.\n";
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        cout<<"Element "<<val<<" popped from the stack.\n";
        return val;
    }
}
int peek(struct stack * ptr,int i){
    if((ptr->top - i + 1)<0){
        return -1;
    }
    else{
        return ptr->arr[ptr->top - i + 1];
    }
}

int main(){
    struct stack * s = (struct stack *)malloc(sizeof(struct stack));
    s->size=100;
    s->top=-1;
    s->arr=(int *)malloc(s->size * sizeof(int));
    int num;
    while(1){
        cin>>num;
        switch(num){
            case 1 :
                int data;
                cin>>data;
                push(s,data);
                break; 
            case 2 :
                pop(s);
                break;
            case 3 :
                if(!isempty(s)){
                    cout<<"Elements in the stack: ";
                    for(int j=0;j<=s->top;j++){
                        cout<<peek(s,j)<<" ";
                    }
                    cout<<endl;
                }
                else{
                    cout<<"stack is empty\n";
                }
                break;
            case 4 :
                cout<<"exiting the program\n";
                exit(0);
                break;
            default : 
                cout<<"invalid choice\n";
                break;
        }
    }
return 0;
}