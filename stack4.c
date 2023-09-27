#include<stdio.h>
#include<stdlib.h>
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
int top(struct stack * ptr){
    printf("top value : ");
    return ptr->arr[ptr->top];
}
int bottom(struct stack * ptr){
    printf("bottom value : ");
    return ptr->arr[0];
}
int main(){
    struct stack * s=(struct stack * )malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    push(s,11);
    push(s,12);
    push(s,13);
    push(s,14);
    push(s,15);
    push(s,16);
    for(int j=1;j<=s->top+1;j++){
        printf("position %d element %d\n",j,peek(s,j));
    }
    printf("%d",top(s));
    printf("\n");
    printf("%d",bottom(s));
return 0;
}