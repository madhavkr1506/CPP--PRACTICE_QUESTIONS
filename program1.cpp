#include<iostream>
using namespace std;
struct node {
    int data;
    struct node *next;
    struct node *prev;
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
    struct node * ptrs;
    struct node * ptrl = NULL;
    if(head == NULL){
        return;
    }
    do{
        swapped = 0;
        ptrs = head;
        while(ptrs->next != ptrl){
            if(ptrs->data > ptrs->next->data){
                swap(ptrs->data,ptrs->next->data);
                swapped=1;
            }
            ptrs=ptrs->next;
        }
        ptrl = ptrs; 
    }while(swapped);
}

struct node * insertatbeginning(struct node * head, int data){
    struct node * ptr = (struct node * )malloc(sizeof(struct node ));
    ptr->data=data;
    ptr->next=head;
    ptr->prev=NULL;
    if(head != NULL){
        head->prev = ptr;
    }
    return ptr;
}

struct node * atlastindex(struct node * head, int data){
    struct node * ptr=(struct node *)malloc(sizeof(struct node ));
    struct node * p = head;
    while(p->next != NULL){
        p=p->next;
    }
    ptr->next=NULL;
    ptr->data=data;
    p->next=ptr;
    ptr->prev=p;
    return head;
}

struct node * atanyindex(struct node * head, int data, int index){
    struct node * ptr=(struct node *)malloc(sizeof(struct node ));
    struct node * p=head;
    int i=0;
    while(i != index - 1 && p != NULL){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    ptr->prev=p;
    p->next=ptr;
    if(ptr->next != NULL){
        ptr->next->prev=ptr;
    }
    return head;
}

struct node * deleteatbeginning(struct node * head){
    struct node * p=head;
    head=head->next;
    head->prev=NULL;
    free(p);
    return head;
}
struct node * deleteatindex(struct node * head, int index){
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
int getsize(struct node * head){
    int size=0;
    struct node * current=head;
    while(current != NULL){
        current=current->next;
        size++;
    }
    return size;
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

    head->data=101;
    head->next=second;
    head->prev=NULL;

    second->data=120;
    second->next=third;
    second->prev=head;

    third->data=103;
    third->next=fourth;
    third->prev=second;

    fourth->data=84;
    fourth->next=fifth;
    fourth->prev=third;

    fifth->data=105;
    fifth->next=NULL;
    fifth->prev=fourth;

    // traverse(head);
    // cout<<endl;
    // bubblesort(head);
    // traverse(head);
    // cout<<endl;
    // head=insertatbeginning(head,19);
    // head=atlastindex(head,100);
    // head = atanyindex(head,500,2);
    // head=deleteatbeginning(head);
    // head=deleteatindex(head,2);
    // head=deleteatgivenvalue(head,84);
    // head=deletelastnode(head);
    // traverse(head);
    int size=getsize(head);
    cout<<size;
return 0;
}