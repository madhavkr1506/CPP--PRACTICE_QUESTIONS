#include<iostream>
using namespace std;
struct queue{
    int top;
    int beg;
    int size;
    int * arr;
};
int isempty(struct queue * ptr){
    if(ptr->top == ptr->beg){
        return 1;
    }
    else{
        return 0;
    }
}
int isfull(struct queue * ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}
int peek(struct queue * ptr,int i){
    if((ptr->top - i + 1) < 0){
        return -1;
    }
    else{
        return ptr->arr[ptr->top - i + 1];
    }
}
void enqueue(struct queue * ptr,int value){
    if(isfull(ptr)){
        cout<<"queuee will overflow\n";
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=value;
        cout<<"element enqueue = "<<value<<endl;
    }
}
int dequeue(struct queue * ptr){
    int value=-1;
    if(isempty(ptr)){
        cout<<"queue is in underflow\n";
    }
    else{
        ptr->beg++;
        value=ptr->arr[ptr->beg];
        cout<<"element dequeue = "<<value<<endl;
    }
    return value;
}
int queuetop(struct queue * ptr){
    return ptr->arr[0];

}
int queuebottom(struct queue * ptr){
    return ptr->arr[ptr->top];
}
void bubblesort(struct queue * ptr){
    int n=ptr->top+1;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(ptr->arr[j] > ptr->arr[j+1]){
                swap(ptr->arr[j],ptr->arr[j+1]);
            }
        }
    }
}
int main(){
    struct queue * q=(struct queue *)malloc(sizeof(struct queue));
    q->size=10;
    q->top=-1;
    q->beg=-1;
    q->arr=(int *)malloc(q->size * sizeof(int));
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        int data;
        cin>>data;
        enqueue(q,data);
    }
    bubblesort(q);
    for(int i=1;i<=q->top+1;i++){
        cout<<peek(q,i)<<" ";
    }
return 0;
}