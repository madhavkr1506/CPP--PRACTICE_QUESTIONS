#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int f;
    int r;
    int * arr;
};

int isfull(struct queue * ptr){
    if(ptr->r == ptr->size - 1){
        printf("queue is full\n");
        return 1;
    }
    else{
        return 0;
    }
}
int isempty(struct queue * ptr){
    if(ptr->f == ptr->r){
        printf("queueb is empty\n");
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct queue * ptr, int data){
    if(isfull(ptr)){
        printf("queue overflow %d\n",data);
    }
    else{
        printf("%d\n",data);
        ptr->r=ptr->r+1;
        ptr->arr[ptr->r]=data;
    }
}
int dequeue(struct queue * ptr){
    int a=-1;
    if(isempty(ptr)){
        printf("no elements to dequeue\n");
    }
    else{
        ptr->f++;
        a=ptr->arr[ptr->f];
        printf("%d ",a);
    }
    return a;
}
int main(){
    struct queue * q=(struct queue * )malloc(sizeof(struct queue));
    q->size=5;
    q->f = -1;
    q->r = -1;
    q->arr=(int *)malloc(q->size * sizeof(int));
    // printf("%d\n",isfull(q));
    // printf("%d\n",isempty(q));
    enqueue(q,11);
    enqueue(q,12);
    enqueue(q,13);
    enqueue(q,14);
    enqueue(q,15);
    enqueue(q,16);
    dequeue(q);


return 0;
}