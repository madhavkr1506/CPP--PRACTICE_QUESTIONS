#include<iostream>
using namespace std;
struct queue{
    int size;
    int top;
    int beg;
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
void enqueue(struct queue * ptr, int val){
    if(!isfull(ptr)){
        ptr->top++;
        ptr->arr[ptr->top] = val;
        cout<<"element "<<val<<" enqueue\n";
    }
}
int dequeue(struct queue * ptr){
    int val=-1;
    if(isempty(ptr)){
        cout<<"queue is in underflow\n";
        return -1;
    }
    else{
        ptr->beg++;
        val=ptr->arr[ptr->beg];
        cout<<"dequeue element are "<<val<<endl;
    }
    return val;
}
int peek(struct queue * ptr,int i){
    if((ptr->top - i + 1)<0){
        return -1;
    }
    else{
        return ptr->arr[ptr->top - i + 1];
    }
}

int main(){
    struct queue * q=(struct queue *)malloc(sizeof(struct queue));
    q->size=100;
    q->top=-1;
    q->beg=-1;
    q->arr=(int *)malloc(q->size * sizeof(int));
    int num;
    while(1){
        cin>>num;
        switch(num){
            case 1 :
                int data;
                cin>>data;
                enqueue(q,data);
                break;
            case 2 :
                dequeue(q);
                break;
            case 3 : 
                if(!isempty(q)){
                    cout<<"elements are: ";
                    for(int j=1;j<=q->top;j++){
                        cout<<peek(q,j)<<" ";
                    }
                }
                else{
                    cout<<"queue is empty.\n";
                }
                cout<<endl;
                break;
            case 4 :
                cout<<"exiting the program.\n";
                exit(0);
                break;
            default : 
                cout<<"invalid choioce\n";
                break;
        }
    }
return 0;
}