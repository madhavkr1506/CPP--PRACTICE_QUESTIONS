#include<iostream>
#include<stdlib.h>
using namespace std;

struct node {
    int data;
    struct node * next;
};

void traverselinkedlist(struct node* ptr){
    int i=0;
    while(ptr !=NULL){
        cout<<"Element "<<i+1<<" : "<<ptr->data<<endl;
        ptr=ptr->next;
        i++;
    }
}

struct node * insertatbeginning(struct node * head,int data){
    struct node * ptr=(struct node * )malloc(sizeof(struct node *));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}

struct node * insertinmiddle(struct node * head,int data,int index){
    struct node * ptr=(struct node *)malloc(sizeof(struct node *));
    struct node * p=head;
    int i=0;
    while(i != index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

struct node * insertatend(struct node * head, int data){
    struct node * ptr=(struct node * )malloc(sizeof(struct node *));
    struct node * p=head;
    while(p->next != NULL){
        p=p->next;
    }
    ptr->data=data;
    p->next=ptr;
    ptr->next=NULL;
    return head;
}

int main(){
    struct node* head;
    struct node* second;
    struct node* third;
    struct node* fourth;
    struct node* fifth;

    head=(struct node * )malloc(sizeof(struct node * ));
    second=(struct node * )malloc(sizeof(struct node * ));
    third=(struct node * )malloc(sizeof(struct node * ));
    fourth=(struct node * )malloc(sizeof(struct node * ));
    fifth=(struct node * )malloc(sizeof(struct node * ));

    head->data=11;
    head->next=second;

    second->data=12;
    second->next=third;

    third->data=13;
    third->next=fourth;

    fourth->data=14;
    fourth->next=fifth;

    fifth->data=15;
    fifth->next=NULL;

    cout<<"Linked list before insertion => "<<endl;
    traverselinkedlist(head);

    cout<<"Linked list after insertion => "<<endl;
    // head=insertatbeginning(head,100);
    // insertinmiddle(head,100,2);
    head=insertatend(head,100);
    traverselinkedlist(head);

return 0;
}