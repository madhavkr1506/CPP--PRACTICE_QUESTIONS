#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node * next;
    struct node * prev;
};

void traverse(struct node *ptr){
    int i = 0;
    while(ptr != NULL){
        cout<<"Element "<<i+1<<" : "<<ptr->data<<endl;
        ptr=ptr->next;
        i++;
    }
}

void reverse(struct node * ptr){
    int i=0;
    while(ptr->next != NULL){
        i++;
        ptr=ptr->next;
    }
    int j = i - 1;
    while(ptr != NULL){
        cout<<"Element "<<i+1<<" : "<<ptr->data<<endl;
        ptr=ptr->prev;
        i--;
    }
}

struct node * insertatbeginning(struct node * head, int data){
    struct node * ptr=(struct node *)malloc(sizeof(struct node * ));
    ptr->data=data;
    ptr->next=head;
    ptr->prev=NULL;
    if(head != NULL){
        head->prev=ptr;
    }
    return ptr;
}

int main(){
    struct node * head = NULL;
    struct node * second;
    struct node * third;
    struct node * fourth;

    head=(struct node * )malloc(sizeof(struct node *));
    second=(struct node * )malloc(sizeof(struct node *));
    third=(struct node * )malloc(sizeof(struct node *));
    fourth=(struct node * )malloc(sizeof(struct node *));

    head->data=10;
    head->next=second;
    head->prev=NULL;

    second->data=20;
    second->next=third;
    second->prev=head;

    third->data=30;
    third->next=fourth;
    third->prev=second;

    fourth->data=40;
    fourth->next=NULL;
    fourth->prev=third;

    // traverse(head);
    // cout<<"\n";
    // reverse(head);

    head=insertatbeginning(head,5);
    traverse(head);
    cout<<"\n";
    reverse(head);
return 0;
}


