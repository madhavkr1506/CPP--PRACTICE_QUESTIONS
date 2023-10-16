#include<iostream>
using namespace std;
struct node {
    int data;
    struct node * next;
    struct node * prev;
};
void traverse(struct node * ptr){
    while(ptr->next != NULL){
        ptr=ptr->next;
    }
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->prev;
    }
}

void bubblesort(struct node * head){
    int i,swapped;
    struct node * start;
    struct node * finish=NULL;
    if(head==NULL){
        return;
    }
    do{
        swapped=0;
        start=head;
        while(start->next != finish){
            if(start->data > start->next->data){
                swap(start->data,start->next->data);
                swapped=1;
            }
            start=start->next;
        }
        finish=start;
    }while(swapped);
}

void even(struct node * head){
    struct node * current=head;
    while(current!=NULL){
        if((current->data) % 2 == 0){
            cout<<current->data<<" ";
        }
        current=current->next;
    }
}
// int getsize(struct node * head){
//     int size;
//     struct node * current=head;
//     while(current != NULL){
//         current=current->next;
//         size++;
//     }
//     return size;
// }
int main(){
    struct node * head=nullptr;
    struct node * current=nullptr;
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        struct node * newnode=(struct node *)malloc(sizeof(struct node ));
        cin>>newnode->data;
        newnode->next=nullptr;
        newnode->prev=current;
        if(current != NULL){
            current->next=newnode;
        }
        else{
            head=newnode;
        }
        current=newnode;
    }
    // traverse(head);
    // cout<<endl;
    // bubblesort(head);
    // traverse(head);
    // cout<<endl;
    // even(head);
    
    
}