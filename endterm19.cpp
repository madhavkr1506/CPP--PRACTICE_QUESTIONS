#include<iostream>
using namespace std;
struct node{
    int size;
    int top;
    int *arr;
};
void push(struct node * ptr,int data){
    if(ptr->top == ptr->size - 1){
        cout<<"stack is full\n";
    }
    ptr->top++;
    ptr->arr[ptr->top]=data;
    cout<<"pushing element "<<data<<endl;
}
int pop(struct node * ptr){
    if(ptr->top == -1){
        cout<<"stack is empty\n";
        return -1;
    }
    int val=ptr->arr[ptr->top];
    cout<<"poping element "<<val<<endl;
    ptr->top--;
    return val;

}
int peek(struct node * ptr,int i){
    if((ptr->top -i + 1)< 0){
        return -1;
    }
    return ptr->arr[ptr->top - i +1];
}

void bubblesort(struct node * ptr){
    int n=ptr->top+1;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(ptr->arr[j] < ptr->arr[j+1]){
                swap(ptr->arr[j],ptr->arr[j+1]);
            }
        }
    }
}
int main(){
    struct node * p=(struct node *)malloc(sizeof(struct node ));
    p->size=5;
    p->top=-1;
    p->arr=(int *)malloc(p->size * sizeof(int));
    int choice;
    while(1){
        cin>>choice;
        switch(choice){
            case 1 :
            int num;
            cin>>num;
            for(int i=0;i<num;i++){
                int data;
                cin>>data;
                push(p,data);
            }
            break;
            case 2 :
            pop(p);
            break;
            case 3 :
            for(int j=1;j<=p->top+1;j++){
                cout<<peek(p,j)<<" ";
            }
            break;
            case 4 :
            bubblesort(p);
            for(int j=1;j<=p->top+1;j++){
                cout<<peek(p,j)<<" ";
            }
            break;
            default :
            exit(0);
        }
    }
return 0;
}