#include<iostream>
using namespace std;
struct node {
    int data;
    struct node * next, *prev;
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
    if(head != NULL){
        head->prev=ptr;
    }
    return ptr;
}
struct node * insertatindex(struct node * head,int index,int value){
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    struct node * p=head;
    ptr->data=value;
    int i=0;
    while(i !=index - 1){
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    ptr->prev=p;
    if(ptr->next != NULL){
        ptr->next->prev=ptr;
    }
    p->next=ptr;
    return head;
}
struct node * insertatlast(struct node *head,int data){
    struct node * ptr=(struct node *)malloc(sizeof(struct node ));
    struct node * p=head;
    while(p->next != NULL){
        p=p->next;
    }
    ptr->data=data;
    p->next=ptr;
    ptr->next=NULL;
    ptr->prev=p;
    return head;
}
void bubblesort(struct node * head){
    int swapped,i;
    struct node * start;
    struct node * end=NULL;
    if(head == NULL){
        return;
    }
    do{
        swapped=0;
        start=head;
        while(start->next != end){
            if(start->data > start->next->data){
                swap(start->data,start->next->data);
                swapped=1;
            }
            start=start->next;
        }
        end=start;
    }while(swapped);
}

struct node * deleteatbeginniing(struct node * head){
    struct node * ptr=head;
    head=head->next;
    head->prev=NULL;
    free(ptr);
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
struct node * deleteatlast(struct node * head){
    struct node * p=head;
    struct node * q=head->next;
    while(q->next != NULL){
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
    struct node * head=NULL;
    struct node * current=NULL;
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        struct node * newnode=(struct node *)malloc(sizeof(struct node ));
        cin>>newnode->data;
        newnode->next=NULL;
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
    int value;
    cin>>value;
    // int index;
    // cin>>index;
    // head=insertatindex(head,index,value);
    // head=insertatlast(head,value);
    // head=deleteatbeginniing(head);
    // head=deleteatlast(head);

    // bubblesort(head);
    // head=deleteatindex(head,value);
    head=deleteatvalue(head,value);
    traverse(head);
return 0;
}