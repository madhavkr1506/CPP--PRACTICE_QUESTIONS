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
struct node * insertatindex(struct node * head,int data,int index){
    struct node * ptr=(struct node *)malloc(sizeof(struct node ));
    struct node * p=head;
    int i=0;
    while(i != index - 1){
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
struct node * insertatlast(struct node * head, int data){
    struct node * ptr=(struct node * )malloc(sizeof(struct node ));
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
struct node * deleteatbeg(struct node * head){
    struct node * ptr=head;
    head=head->next;
    head->prev=NULL;
    free(ptr);
    return head;
}
struct node * deleteatindec(struct node * head,int index){
    struct node *p=head;
    struct node *q=head->next;
    for(int i=0;i<index - 1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    p->next->prev=p;
    free(q);
    return head;
}
struct node * delatlast(struct node * head){
    struct node * p=head;
    struct node *q = head->next;
    while(q->next != NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}
struct node * deleteatval(struct node * head,int val){
    struct node * p=head;
    struct node * q=head->next;
    while(q->data != val && q->next != NULL){
        p=p->next;
        q=q->next;
    }
    if(q->data == val){
        p->next=q->next;
        p->next->prev=p;
        free(q);
    }
    return head;
}
void bubblesort(struct node * head){
    int i,swapped;
    struct node * start;
    struct node * last=NULL;
    if(head == NULL){
        return;
    }
    do{
        swapped=0;
        start=head;
        while(start->next != last){
            if(start->data > start->next->data){
                swap(start->data,start->next->data);
                swapped=1;
            }
            start=start->next;
        }
        last=start;
    }while(swapped);
}
int main(){
    struct node * head =nullptr;
    struct node * current=nullptr;
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        struct node * newnode = (struct node *)malloc(sizeof(struct node ));
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
    // int val;
    // cin>>val;
    // int index;
    // cin>>index;
    // head=insertatbeginning(head,val);
    // head=insertatindex(head,val,index);
    // head=insertatlast(head,val);
    // head=deleteatbeg(head);
    // head=deleteatindec(head,val);
    // head=delatlast(head);
    // head=deleteatval(head,val);
    // bubblesort(head);
    // traverse(head);
return 0;
}