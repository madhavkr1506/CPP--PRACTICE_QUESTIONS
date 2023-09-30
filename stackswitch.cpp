#include<iostream>
#include<stdlib.h>
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
        return 0;
    }
}
void push(struct stack * ptr, int val){
    if(isfull(ptr)){
        printf("overflow element : %d\n",val);
    }
    else{
        printf("push element : %d\n",val);
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}
int pop(struct stack * ptr){
    if(isempty(ptr)){
        printf("underflow condition \n");
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
        printf("poped element : %d\n",val);
    }
}
int peek(struct stack * ptr, int i){
    if(ptr->top-i+1 < 0){
        printf("not a valid position\n");
        return -1;
    }
    else{
        return ptr->arr[ptr->top-i+1];
    }
}
int main(){
    struct stack * s=(struct stack * )malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    int choice ,value;
    // cin>>choice;
    do{
        cin>>choice;
        switch(choice){
            case 1 : 
            int numele;
            cin>>numele;
            for(int i=0;i<numele;i++){
                cin>>value;
                push(s,value);
            }
            break;
            case 2 :
            pop(s);
            break;
            case 3:
            for(int j=1;j<=s->top+1;j++){
                cout<<peek(s,j)<<"\t";
            }
            break;
            case 4 :
            break;


        }
    }while(choice != 4);
return 0;
}