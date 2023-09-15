#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node * next;
};

void traverselinkedlist(struct node * ptr){
    int i=0;
    while(ptr != NULL){
        cout<<"Element "<<i+1<<" : "<<ptr->data<<endl;
        ptr=ptr->next;
        i++;
    }
}

struct node * insertatbeginning(struct node * head,int data){
    struct node * ptr = (struct node * )malloc(sizeof(struct node * ));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}

struct node * insertatindex(struct node * head,int data,int index){
    struct node * ptr = (struct node * )malloc(sizeof(struct node * ));
    struct node * p = head;
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

int main(){
    struct node * head;
    struct node * second;
    struct node * third;
    struct node * fourth;
    struct node * fifth;

    head=(struct node * )malloc(sizeof(struct node *));
    second=(struct node * )malloc(sizeof(struct node *));
    third=(struct node * )malloc(sizeof(struct node *));
    fourth=(struct node * )malloc(sizeof(struct node *));
    fifth=(struct node * )malloc(sizeof(struct node *));

    head->data=100;
    head->next=second;

    second->data=200;
    second->next=third;

    third->data=300;
    third->next=fourth;

    fourth->data=400;
    fourth->next=fifth;

    fifth->data=500;
    fifth->next=NULL;

    traverselinkedlist(head);

    // head = insertatbeginning(head,600);
    cout<<endl;
    head = insertatindex(head,600,2);

    traverselinkedlist(head);
return 0;
}