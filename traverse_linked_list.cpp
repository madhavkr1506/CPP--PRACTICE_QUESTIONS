#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node * next;
};

void singlyLinkedList(struct node * ptr){
    int i=0;
    while(ptr != NULL){
        cout<<"Element "<<i+1<<" : "<<ptr->data<<endl;
        ptr=ptr->next;
        i++;
    }
}

int main(){
    struct node * head;
    struct node * second;
    struct node * third;
    struct node * fourth;
    struct node * fifth;

    head=(struct node *)malloc(sizeof(struct node *));
    second=(struct node *)malloc(sizeof(struct node *));    
    third=(struct node *)malloc(sizeof(struct node *));    
    fourth=(struct node *)malloc(sizeof(struct node *));    
    fifth=(struct node *)malloc(sizeof(struct node *));    
    

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=fourth;

    fourth->data=4;
    fourth->next=fifth;

    fifth->data=5;
    fifth->next=NULL;

    singlyLinkedList(head);
return 0;
}