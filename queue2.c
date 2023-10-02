#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
struct queue{
    int size;
    int f;
    int r;
    char ** arr;
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
void push(struct queue * ptr,const char * val){
    if(isfull(ptr)){
        printf("overflow\n");
    }
    else{
        ptr->r++;
        ptr->arr[ptr->r]=strdup(val);
        printf("%s\n",val);
    }
}
char * delete(struct queue * ptr){
    char  * a = NULL;
    if(isempty(ptr)){
        printf("underflow\n");
    }
    else{
        ptr->f++;
        a=ptr->arr[ptr->f];
    }
    return a;
}
char * top(struct queue * ptr){
    return ptr->arr[0];
}
char * bottom(struct queue * ptr){
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
    q.arr=(char **)malloc(q.size * sizeof(char *));
    push(&q,"write content");
    push(&q,"copy condent");
    push(&q,"submit copy");
    push(&q,"hello sir");
    push(&q,"hello maam");
    printf("%s\n",top(&q));
    printf("%s\n",bottom(&q));
    // push(&q,16);
    // printf("%d",delete(&q));
    // printf("%d\n",top(&q));
    // printf("%d\n",bottom(&q));
    // deleteall(&q);
return 0;
}