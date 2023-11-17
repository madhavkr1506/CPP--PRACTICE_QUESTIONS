#include<iostream>
using namespace std;
struct node{
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
struct node * insertatbeginning(struct node * head,int data){
    struct node * ptr=(struct node *)malloc(sizeof(struct node ));
    ptr->data=data;
    ptr->next=head;
    ptr->prev=NULL;
    if(head!=NULL){
        head->prev=ptr;
    }
    return ptr;
}
struct node * insertatindex(struct node * head,int data,int index){
    struct node * ptr=(struct node *)malloc(sizeof(struct node ));
    struct node * p=head;
    ptr->data=data;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->prev=p;
    ptr->next=p->next;
    if(ptr->next != NULL){
        ptr->next->prev=ptr;
    }
    p->next=ptr;
    return head;
} 
struct node * insertatlast(struct node * head,int data){
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    struct node * p=head;
    while(p->next != NULL){
        p=p->next;
    }
    ptr->data=data;
    ptr->next=NULL;
    ptr->prev=p;
    p->next=ptr;
    return head;
}
void bubblesort(struct node * head){
    int swapped;
    struct node * start;
    struct node * last=NULL;
    if(head==NULL){
        return;
    }
    do{
        swapped=0;
        start=head;
        while(start->next != last){
            if(start->data > start->next->data){
                swap(start->data, start->next->data);
                swapped=1;
            }
            start=start->next;
        }
        last=start;
    }while(swapped);
}
struct node *deleteatbeginning(struct node * head){
    struct node *p=head;
    head=head->next;
    head->prev=NULL;
    free(p);
    return head;
}
struct node * deleteatindex(struct node * head,int index){
    struct node * p=head;
    struct node * q=head->next;
    for(int i=0;i<index - 1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    p->next->prev=p;
    free(q);
    return head;
}
struct node * deletelastnode(struct node * head){
    struct node * p=head;
    struct node * q=head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}
struct node * deleteatvalue(struct node * head,int value){
    struct node * p=head;
    struct node * q=head->next;
    while(q->data != value && q->next != NULL){
        p=p->next;
        q=q->next;
    }
    if(q->data == value){
        p->next=q->next;
        p->next->prev=p;
        free(q);
    }
    return head;
}
int main(){
    struct node * head=nullptr;
    struct node * current=nullptr;
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        struct node * newnode=(struct node *)malloc(sizeof(struct node ));
        int data;
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
    traverse(head);
    cout<<endl;
    int insert1;
    cin>>insert1;
    // int index;
    // cin>>index;
    // head=insertatindex(head,insert1,index);
    // head=insertatlast(head,insert1);
    // head=insertatbeginning(head,insert1);
    // bubblesort(head);
    // head=deleteatbeginning(head);
    // head=deleteatindex(head,index);
    // head=deletelastnode(head);
    head=deleteatvalue(head,insert1);
    traverse(head);
return 0;
}