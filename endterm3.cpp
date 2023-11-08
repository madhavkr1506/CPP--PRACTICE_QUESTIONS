#include<iostream>
using namespace std;
struct node{
    int size;
    int top;
    int *arr;

};
int isfull(struct node * ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}
int isempty(struct node * ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int peek(struct node * ptr,int i){
    if((ptr->top - i + 1) < 0){
        return -1;
    }
    else{
        return ptr->arr[ptr->top - i + 1];
    }
}
void push(struct node * ptr,int value){
    if(isfull(ptr)){
        cout<<"strck will overflow\n";
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=value;
        cout<<"pushing element = "<<value<<endl;
    }
}
int pop(struct node * ptr){
    if(isempty(ptr)){
        cout<<"stack is in underflow condition.\n";
    }
    else{
        int value=ptr->arr[ptr->top];
        cout<<"popped = "<<value<<endl;
        ptr->top--;
        return value;

    }
}
int stacktop(struct node * ptr){
    return ptr->arr[ptr->top];
}
int stackbottom(struct node * ptr){
    return ptr->arr[0];
}
void bubblesort(struct node *ptr){
    int swapped=0;
    int n=ptr->top+1;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(ptr->arr[j] > ptr->arr[j+1]){
                swap(ptr->arr[j],ptr->arr[j+1]);
                swapped=1;
            }
        }
    }
}
int main(){
    struct node * stack=(struct node *)malloc(sizeof(struct node ));
    stack->size=10;
    stack->top=-1;
    stack->arr=(int *)malloc(stack->size * sizeof(int));
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        int data;
        cin>>data;
        push(stack,data);
    }
    for(int i=1;i<=stack->top+1;i++){
        cout<<peek(stack,i)<<" ";
    }
    cout<<endl;
    bubblesort(stack);
    // pop(stack);
    // cout<<endl;
    for(int i=1;i<=stack->top+1;i++){
        cout<<peek(stack,i)<<" ";
    }
return 0;
}