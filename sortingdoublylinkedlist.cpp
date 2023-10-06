#include<iostream>
#include<stdlib.h>
using namespace std;
struct node {
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

struct node * insertatbeginning(struct node * head, int data){
    struct node * ptr=(struct node *)malloc(sizeof(struct node ));
    ptr->data=data;
    ptr->next=head;
    ptr->prev=NULL;
    if(head != NULL){
        head->prev=ptr;
    }
    return ptr;
}

struct node * atlastnode(struct node * head, int data){
    struct node * ptr = (struct node *)malloc(sizeof(struct node ));
    struct node * p = head;
    while(p->next != NULL){
        p=p->next;
    }
    ptr->data=data;
    ptr->next=NULL;
    p->next=ptr;
    ptr->prev=p;
    return head;
}

struct node * atanyindex(struct node * head,int index,int data){
    struct node * ptr=(struct node *)malloc(sizeof(struct node ));
    struct node * p=head;
    int i=0;
    while(i != index-1 && p != NULL){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    ptr->prev=p;
    if(ptr->next != NULL){
        ptr->next->prev=ptr;
    }
    return head;
}

struct node * deleteatbeginning(struct node * head){
    struct node * ptr=head;
    head=head->next;
    head->prev=NULL;
    free(ptr);
    return head;
}

struct node * deleteatlast(struct node * head){
    struct node * p = head;
    struct node * q = head->next;
    while(q->next != NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

struct node * atgivenvalue(struct node * head,int data){
    struct node * p=head;
    struct node * q=head->next;
    while(q->data != data && q->next != NULL){
        p=p->next;
        q=q->next;
    }
    if(q->data == data){
        p->next = q->next;
        p->next->prev=p;
        free(q);
    }
    return head;
}

struct node * atindex(struct node * head,int index){
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



void bubblesort(struct node * head){
    int swapped,i;
    struct node * ptrs;
    struct node * ptrl = NULL;
    if(head == NULL){
        return;
    }
    do{
        swapped = 0;
        ptrs=head;
        while(ptrs->next != ptrl){
            if(ptrs->data > ptrs->next->data){
                swap(ptrs->data,ptrs->next->data);
                swapped = 1;
            }
            ptrs=ptrs->next;
        }
        ptrl=ptrs;
    }while(swapped);
}
int main(){
    struct node * head;
    struct node * second;
    struct node * third;
    struct node * fourth;

    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    fourth=(struct node *)malloc(sizeof(struct node));

    head->data=110;
    head->next=second;
    head->prev=NULL;

    second->data=102;
    second->next=third;
    second->prev=head;

    third->data=130;
    third->next=fourth;
    third->prev=second;

    fourth->data=104;
    fourth->next=NULL;
    fourth->prev=third;

    reverse(head);
    cout<<"\n";
    // head=insertatbeginning(head,10);
    // head=atlastnode(head,15);
    // head=atanyindex(head,2,100);
    // head=deleteatbeginning(head);
    // head=deleteatlast(head);
    // head=atgivenvalue(head,12);
    // head=atindex(head,2);
    bubblesort(head);
    reverse(head);
}