#include<iostream>
#include<stdlib.h>
#include<string>
#include<malloc.h>
using namespace std;
struct queue{
    int size;
    int r;
    int f;
    int * arr;
};
int isfull(struct queue * ptr){
    if(ptr->r == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}
int isempty(struct queue * ptr){
    if(ptr->f == ptr->r){
        return 1;
    }
    else{

        return 0;
    }
}
int queuuetop(struct queue * ptr){
    return ptr->arr[0];
}
int queuebottom(struct queue * ptr){
    return ptr->arr[ptr->r];
}
void enqueue(struct queue * ptr, int data){
    if(isfull(ptr)){
        cout<<"you can't enqueue here because it is already full\n";
    }
    else{
        ptr->r++;
        ptr->arr[ptr->r]=data;
        cout<<"enqueue elements are "<<data<<endl;
    }
}
int dequeue(struct queue * ptr){
    int a=-1;
    if(isempty(ptr)){
        cout<<"you can't dequeue from this queue because it is an empty queue\n";
    }
    else{
        ptr->f++;
        a=ptr->arr[ptr->f];
        cout<<"dequeue element is "<<a<<endl;
    }
    return a;
}
int peek(struct queue * ptr ,int i){
    if((ptr->r - i + 1) < 0){
        cout<<"it is an invalid position\n";
    }
    else{
        return ptr->arr[ptr->r - i + 1];
    }
}
void bubblesort(struct queue * ptr){
    if(isempty(ptr)){
        return;
    }
    int n=ptr->r + 1;
    for(int i=0;i<n - 1;i++){
        for (int j=0;j<n - i - 1;j++){
            if(ptr->arr[j] > ptr->arr[j+1]){
                swap(ptr->arr[j],ptr->arr[j+1]);
            }
        }
    }
}
int main(){
    struct queue *q=(struct queue *)malloc(sizeof(struct queue));
    q->size = 10;
    q->f=-1;
    q->r=-1;
    q->arr=(int *)malloc(q->size * sizeof(int ));
    // cout<<isfull(q);
    enqueue(q,101);
    enqueue(q,120);
    enqueue(q,103);
    enqueue(q,140);
    enqueue(q,15);
    enqueue(q,165);
    enqueue(q,177);
    enqueue(q,138);
    enqueue(q,190);
    enqueue(q,210);
    // dequeue(q);
    // enqueue(q,11);
    for(int j = 1;j <= q->r + 1;j++){
        cout<<peek(q,j)<<" ";
    }
    cout<<endl;
    for(int j = q->r + 1;j > 0;j--){
        cout<<peek(q,j)<<" ";
    }
    cout<<endl;
    bubblesort(q);
    for(int j = 1;j <= q->r + 1;j++){
        cout<<peek(q,j)<<" ";
    }
    cout<<endl;
    for(int j = q->r + 1;j > 0;j--){
        cout<<peek(q,j)<<" ";
    }
return 0;
}