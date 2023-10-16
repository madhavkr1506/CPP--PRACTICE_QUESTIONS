#include<iostream>
using namespace std;
struct queue{
    int size;
    int r;
    int f;
    int * arr;
};
int queuetop(struct queue * ptr){
    return ptr->arr[0];
}

int queuebottom(struct queue * ptr){
    return ptr->arr[ptr->r];
}

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

void enqueue(struct queue * ptr,int val){
    if(isfull(ptr)){
        cout<<"overflow condition\n";
    }
    else{
        ptr->r++;
        ptr->arr[ptr->r]=val;
        cout<<"element "<<val<<endl;
    }
}

int dequeue(struct queue * ptr){
    int a = -1;
    if(isempty(ptr)){
        cout<<"underflow condition\n";
    }
    else{
        ptr->f++;
        a=ptr->arr[ptr->f];
        // ptr->f++;
    }
    return a;
}

int peek(struct queue * ptr, int i){
    if((ptr->r - i + 1) < 0){
        cout<<"invalid position\n";
    }
    else{
        return ptr->arr[ptr->r - i + 1];
    }
}
int main(){
    struct queue * q =(struct queue *)malloc(sizeof(struct queue));
    q->size=10;
    q->r=-1;
    q->f=-1;
    q->arr=(int *)malloc(q->size * sizeof(int ));
    enqueue(q,11);
    enqueue(q,12);
    enqueue(q,13);
    for(int j=1;j<=q->r+1;j++){
        cout<<peek(q,j)<<" ";
    }
    cout<<endl;
    cout<<dequeue(q);
    // cout<<endl;
    // cout<<dequeue(q);
    cout<<endl;
    for(int j=1;j<=q->r-q->f;j++){
        cout<<peek(q,j)<<" ";
    }

return 0;
}