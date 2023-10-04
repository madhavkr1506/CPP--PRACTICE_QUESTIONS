#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
    int data;
    struct node * next;
    struct node * prev;
};
// traverse case
void traverse(struct node * ptr){
    while(ptr != NULL){
        cout<<ptr->data<<"\t";
        ptr=ptr->next;
    }
}
// reverse case;
void doublylinkedlistTraversal(struct node * ptr){
    while(ptr->next != NULL){
        ptr=ptr->next;
    }
    while(ptr != NULL){
        cout<<ptr->data<<"\t";
        ptr=ptr->prev;
    }
}
// struct node * insertatbeginning(struct node * head , int data){
//     struct node * ptr=(struct node *)malloc(sizeof(struct node ));
//     ptr->data=data;
//     ptr->next=head;
//     ptr->prev=NULL;
//     if(head != NULL){
//         head->prev=ptr;
//     }
//     return ptr;
// }
 // insert in between
// struct node * insertinbetween(struct node * head,int index,int data){
//     struct node * ptr=(struct node * )malloc(sizeof(struct node ));
//     struct node * p=head;
//     int i=0;
//     while(i != index - 1){
//         p=p->next;
//         i++;
//     } 
//     ptr->data=data;
//     ptr->next=p->next;
//     p->next=ptr;
//     ptr->prev=p;
//     return head;    
// }

// insert at last node ;
struct node * insertatlastnode(struct node * head, int data){
    struct node * ptr=(struct node * )malloc (sizeof(struct node ));
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

// case 1 : delete first element
struct node * deleteatnode (struct node * head){
    struct node * ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
// case 2 : delete in between 
struct node * deleteatindex(struct node * head, int index){
    struct node * p = head;
    struct node * q = head->next;
    for(int i=0;i<index - 1;i++){
        p=p->next;
        q=q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}
// case 3 : delete last node 
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
// case 4 : delete at given value 
struct node * deleteatgivenvalue(struct node * head, int value){
    struct node * p=head;
    struct node * q=head->next;
    while(q->data != value && q->next != NULL){
        p=p->next;
        q=q->next;
    }
    if(q->data == value){
        p->next=q->next;
        free(q);
    }
    return head;
}
// insert at beginning
struct node * insertatbeginning(struct node * head, int data){
    struct node * ptr=(struct node*)malloc(sizeof(struct node ));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}
//  // insert in between
// struct node * insertinbetween(struct node * head,int index,int data){
//     struct node * ptr=(struct node * )malloc(sizeof(struct node ));
//     struct node * p=head;
//     int i=0;
//     while(i != index - 1){
//         p=p->next;
//         i++;
//     } 
//     ptr->data=data;
//     ptr->next=p->next;
//     p->next=ptr;
//     return head;
    
// }
// // insert at last node ;
// struct node * insertatlastnode(struct node * head, int data){
//     struct node * ptr=(struct node * )malloc (sizeof(struct node ));
//     struct node * p=head;
//     while(p->next != NULL){
//         p=p->next;
//     }
//     ptr->data=data;
//     p->next=ptr;
//     ptr->next=NULL;
//     return head;
// }
int main(){
    struct node * head;
    struct node * second;
    struct node * third;
    struct node * fourth;
    struct node * fifth;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node ));
    fifth = (struct node *)malloc(sizeof(struct node));
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
    // cout<<"reverse case : ";
    // traverse(head);
    // cout<<endl;
    // cout<<"reverse case : ";
    // doublylinkedlistTraversal(head);
    // cout<<endl;
    // head=insertatbeginning(head,10);
    // cout<<"reverse case : ";
    // traverse(head);
    // cout<<endl;
    // cout<<"reverse case : ";
    // doublylinkedlistTraversal(head);
    // head=deleteatnode(head);
    // head=deleteatindex(head,2);
    // head=deletelastnode(head);
    // head=deleteatgivenvalue(head,14);
    // head=insertinbetween(head,2,99);
    head=insertatlastnode(head,100);
    // head=insertatbeginning(head,78);
    // traverse(head);
    cout<<endl;
    // cout<<"reverse case : ";
    doublylinkedlistTraversal(head);

return 0;
}