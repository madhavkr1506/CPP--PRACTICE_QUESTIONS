#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
void linkedlisttraverse(struct node * ptr){
    while(ptr != NULL){
        printf("element %d\n",ptr->data);
        ptr=ptr->next;
    }
}
int isempty(struct node * top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int isfull(struct node * top){
    struct node *n = (struct node *)malloc(sizeof(struct node *));
    if(n == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

struct node * push(struct node * top,int data){
    if(isfull(top)){
        printf("stack overflow");
    }
    else{
        struct node * n = (struct node *)malloc(sizeof(struct node));
        n->data=data;
        n->next=top;
        top=n;
        return top;
    }
}
int pop(struct node ** top){
    if(isempty(*top)){
        printf("stack underflow\n");
    }
    else{
        struct node * n=*top;
        *top=(*top)->next;
        int x=n->data;
        free(n);
        return x;
    }
}
int main(){
    struct node * top = NULL;
    top=push(top,11);
    top=push(top,12);
    top=push(top,13);
    linkedlisttraverse(top);
    int ele = pop(&top);
    printf("popped element %d\n",ele);
    linkedlisttraverse(top);
return 0;
}