#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
struct queue{
    int size;
    int f;
    int r;
    int * arr;
};
int isempty(struct queue * ptr){
    if(ptr->f == ptr->r){
        return 1;
    }
    else{
        return 0;
    }
}
int isfull(struct queue * ptr){
    if(ptr->r == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct queue * ptr,int val){
    if(isfull(ptr)){
        printf("overflow\n");
    }
    else{
        ptr->r++;
        ptr->arr[ptr->r]=val;
        printf("%d\n",val);
    }
}
int delete(struct queue * ptr){
    int a = -1;
    if(isempty(ptr)){
        printf("underflow\n");
    }
    else{
        ptr->f++;
        a=ptr->arr[ptr->f];
    }
    return a;
}
int top(struct queue * ptr){
    return ptr->arr[0];
}
int bottom(struct queue * ptr){
    return ptr->arr[ptr->r];
}
void deleteall(struct queue * ptr){
    while(!isempty(ptr)){
        int removed = delete(ptr);
        printf("%d\t",removed);
    }
}
int main(){
    struct queue q;
    q.size=5;
    q.f=-1;
    q.r=-1;
    q.arr=(int *)malloc(q.size * sizeof(int));
    push(&q,11);
    push(&q,12);
    push(&q,13);
    push(&q,14);
    push(&q,15);
    // push(&q,16);
    // printf("%d",delete(&q));
    // printf("%d\n",top(&q));
    // printf("%d\n",bottom(&q));
    deleteall(&q);
return 0;
}