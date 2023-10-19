#include<iostream>
using namespace std;

struct queue{
    int size;
    int f;
    int r;
    int * arr;
};

int isempty(struct queue * ptr){
    if(ptr->r == ptr->f){
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

void enqueue(struct queue * ptr,int data){
    if(isfull(ptr)){
        cout<<"overflow\n";
    }
    else{
        ptr->r++;
        ptr->arr[ptr->r]=data;
        cout<<"enqueue "<<data<<endl;
    }
}

int dequeue(struct queue * ptr){
    int a = -1;
    if(isempty(ptr)){
        cout<<"undreflow\n";
    }
    else{
        ptr->f++;
        a=ptr->arr[ptr->f];
        cout<<"dequeue "<<a<<endl;
    }
    return a;
}

int queuetop(struct queue * ptr){
    return ptr->arr[0];
}

int queuebottom(struct queue * ptr){
    return ptr->arr[ptr->r];
}

int peek(struct queue * ptr , int i){
    if((ptr->r - i + 1) < 0){
        cout<<"invalid position\n";
        return -1;
    }
    else{
        return ptr->arr[ptr->r - i + 1];
    }
}

void bubblesort(struct queue * ptr){
    if(ptr == NULL){
        return;
    }
    int n=ptr->r + 1;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(ptr->arr[j]>ptr->arr[j+1]){
                swap(ptr->arr[j],ptr->arr[j+1]);
            }
        }
    }
}
int main(){
    struct queue * q = (struct queue * )malloc(sizeof(struct queue));
    q->size=10;
    q->r=-1;
    q->f=-1;
    q->arr=(int * )malloc(q->size * sizeof(int));
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        int data;
        cin>>data;
        enqueue(q,data);
    }
    for(int j=1;j<=q->r + 1;j++){
        cout<<peek(q,j)<<" ";
    }
    cout<<endl;
    // dequeue(q);
    bubblesort(q);
    for(int j=1;j<=q->r - q->f;j++){
        cout<<peek(q,j)<<" ";
    }

return 0;
}