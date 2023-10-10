#include<stdio.h>
#include <string.h>
#include<malloc.h>
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
int stacktop(struct stack * ptr){
    return ptr->arr[ptr->top];
}
int stackbottom(struct stack * ptr){
    return ptr->arr[0];
}
int pop(struct stack * ptr){
    if(isempty(ptr)){
        printf("stack is in underflow condition\n");
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
void push(struct stack * ptr,int data){
    if(isfull(ptr)){
        printf("stack will be overflow\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=data;
    }
}
int peek(struct stack * ptr,int i){
    if((ptr->top - i + 1) < 0){
        printf("not a valid position\n");
        return -1;
    }
    else{
        return ptr->arr[ptr->top - i + 1];
    }
}
void copystack(struct stack * ptr1,struct stack * ptr2){
    while(!isempty(ptr1)){
        int element=pop(ptr1);
        if(ptr1 != NULL){
            push(ptr2,element);
        }
    }
}
int main(){
    struct stack * stack1 = (struct stack *)malloc(sizeof(struct stack));
    stack1->size=10;
    stack1->top=-1;
    stack1->arr=(int *)malloc(stack1->size * sizeof(int));
    struct stack * stack2 = (struct stack *)malloc(sizeof(struct stack));
    stack2->size=10;
    stack2->top=-1;
    stack2->arr=(int *)malloc(stack2->size * sizeof(int));

    push(stack1,11);
    push(stack1,12);
    push(stack1,13);
    push(stack1,14);
    push(stack1,15);
    push(stack1,16);
    push(stack1,17);
    push(stack1,18);
    push(stack1,19);
    push(stack1,20);

    // for(int j=1;j<=stack1->top+1;j++){
    //     printf("element %d and place %d\n",peek(stack1,j),j);
    // }
    // printf("\n");
    // for(int j=stack1->top+1;j>=1;j--){
    //     printf("element %d and place %d\n",peek(stack1,j),j);
    // }
    // printf("\n");
    copystack(stack1,stack2);
    for(int j=1;j<=stack2->top+1;j++){
        printf("element %d and place %d\n",peek(stack2,j),j);
    }
    printf("\n");
    for(int j=stack2->top+1;j>=1;j--){
        printf("element %d and place %d\n",peek(stack2,j),j);
    }

return 0;
}