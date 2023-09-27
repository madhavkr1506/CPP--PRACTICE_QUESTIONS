#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int * arr;
};

int isEmpty(struct stack * ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack * ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack * ptr, int val){
    if(isFull(ptr)){
        printf("stack will overflow ! cannot push %d val to the stack\n",val);
    }
    else{
        printf("%d value will be push into the stack\n",val);
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("stack is in underflow1 you can perform pop function \n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        printf("%d value will be pop\n",val);
        return val;
    }
}


int main(){
    struct stack *s = (struct stack * )malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    printf("stcak has been created successfully\n");
    printf("before pushing %d\n",isFull(s));
    printf("before pushing %d\n",isEmpty(s));

    push(s,10);
    push(s,11);
    push(s,12);
    push(s,13);
    push(s,14);
    push(s,15);
    push(s,16);
    push(s,17);
    push(s,18);


    printf("after pushing %d\n",isFull(s));
    printf("after pushing %d\n",isEmpty(s));


    pop(s);

    // s->arr[0]=1;
    // s->top++;
    // s->arr[1]=2;
    // s->top++;
    // s->arr[3]=3;
    // s->top++;
    // s->arr[4]=4;
    // s->top++;
    // s->arr[5]=5;
    // s->top++;

    // if(isFull(s)){
    //     printf("stack will be overflow");
    // }
    // else{
    //     // s->top++;
    //     s->arr[s->top];
    //     // s->top++;
    // }

return 0;
}