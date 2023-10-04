#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
    int data;
    struct node * next;
    struct node * prev;
};

void reverse(struct node * ptr){
    while(ptr->next != NULL){
        ptr=ptr->next;
    }
    while(ptr != NULL){
        cout<<ptr->data<<"\t";
        ptr=ptr->prev;
    }
}

struct node * insertatbeginning(struct node *head,int data){
    struct node * ptr=(struct node *)malloc(sizeof(struct node ));
    ptr->data=data;
    ptr->next=head;
    ptr->prev=NULL;
    if(head != NULL){
        head->prev=ptr;
    }
    return ptr;
}

struct node * insertatindex(struct node * head, int data,int index){
    struct node * ptr=(struct node *)malloc(sizeof(struct node ));
    struct node * p=head;
    ptr->data=data;
    int i=0;
    while(i != index-1 && p != NULL){
        p=p->next;
        i++;
    }
    
    ptr->next=p->next;
    p->next=ptr;
    ptr->prev=p;
    if(ptr->next != NULL){
        ptr->next->prev=ptr;
    }
    return head;
}

struct node * insertatlastnode(struct node * head,int data){
    struct node * ptr=(struct node *)malloc(sizeof(struct node ));
    struct node * p=head;
    while(p->next != NULL){
        p=p->next;
    }
    ptr->data=data;
    ptr->next=NULL;
    p->next=ptr;
    ptr->prev=p;
    return head;
}

struct node * deleteatbeginning(struct node * head){
    struct node * ptr=head;
    head=head->next;
    head->prev=NULL;
    free(ptr);
    return head;
}

struct node * deleteatindex(struct node * head,int index){
    struct node * p=head;
    struct node * q=head->next;
    for(int i=0;i<index-1;i++){
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
    while(q->next != NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

struct node * deleteatgivenvalue(struct node * head, int value){
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
    struct node * head;
    struct node * second;
    struct node * third;
    struct node * fourth;
    struct node * fifth;

    head=(struct node *)malloc(sizeof(struct node ));
    second=(struct node *)malloc(sizeof(struct node ));
    third=(struct node *)malloc(sizeof(struct node ));
    fourth=(struct node *)malloc(sizeof(struct node ));
    fifth=(struct node *)malloc(sizeof(struct node ));

    head->data=11;
    head->next=second;
    head->prev=NULL;

    second->data=12;
    second->next=third;
    second->prev=head;

    third->data=13;
    third->next=fourth;
    third->prev=second;

    fourth->data=14;
    fourth->next=fifth;
    fourth->prev=third;

    fifth->data=15;
    fifth->next=NULL;
    fifth->prev=fourth;

    // reverse(head);
    // head=insertatbeginning(head,10);
    // head=insertatindex(head,22,2);
    // head=insertatlastnode(head,100);

    // head=deleteatbeginning(head);
    // head=deleteatindex(head,2);
    // head=deletelastnode(head);
    head=deleteatgivenvalue(head,14);
    reverse(head);

return 0;
}