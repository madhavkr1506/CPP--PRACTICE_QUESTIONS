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

struct node * insertatlast(struct node * head, int data){
    struct node * ptr=(struct node *)malloc(sizeof(struct node ));
    struct node * p=head;
    ptr->data=data;
    while(p->next != NULL){
        p=p->next;
    }
    ptr->next=NULL;
    p->next=ptr;
    ptr->prev=p;
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
            if(start->data < start->next->data){
                swap(start->data,start->next->data);
                swapped=1;
            }
            start=start->next;
        }
        last=start;
    }while(swapped);
}

struct node * insertatindex(struct node * head,int data,int index){
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    struct node * p=head;
    int i=0;
    while(i != index - 1 && p != NULL){
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

struct node * deletelast(struct node * head){
    struct node * p=head;
    struct node * q=head->next;
    while(q->next != NULL){
        p=p->next;
        q=q->next;
    }
    p=p->next=NULL;
    free(q);
    return head;
}

struct node * deleteatvalue(struct node * head, int val){
    struct node * p = head;
    struct node * q = head->next;
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
int main(){
    struct node * head = nullptr;
    struct node * current = nullptr;
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
        current = newnode;
    }
    cout<<endl;
    traverse(head);
    cout<<endl;
    // int data;
    // cin>>data;
    // head=insertatbeginning(head,data);
    // traverse(head);
    // cout<<endl;
    // int value;
    // cin>>value;
    // head=insertatlast(head,value);
    // traverse(head);
    // cout<<endl;
    // int value1;
    // cin>>value1;
    // int index;
    // cin>>index;
    // head=insertatindex(head,value1,index);
    // traverse(head);
    // cout<<endl;
    // bubblesort(head);
    // traverse(head);
    // cout<<endl;
    // head=deleteatbeginning(head);
    // int deleteatin;
    // cin>>deleteatin;
    // head=deleteatindex(head,deleteatin);
    // head=deletelast(head);
    int val;
    cin>>val;
    head=deleteatvalue(head,val);
    traverse(head);


return 0;
}