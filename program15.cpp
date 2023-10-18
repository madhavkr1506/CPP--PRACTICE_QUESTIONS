#include<iostream>
using namespace std;
struct node {
    int data;
    struct node * next;
    struct node * prev;
};
void traverse(struct node * ptr){
    if(ptr == NULL){
        return;
    }
    while(ptr->next != NULL){
        ptr=ptr->next;
    }
    while(ptr != NULL){
        cout<<ptr->data<<" ";
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

struct node * insertatlastnode(struct node * head, int data) {
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;

    if (head == NULL) {
        head = ptr;
    } else {
        struct node * p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = ptr;
        ptr->prev = p;
    }

    return head;
}


int main(){
    struct node * head=NULL;
    int n;
    cin>>n;
    int arr[n];
    for (int i =0;i<n;i++){
        cin>>arr[i];
        // head=insertatbeginning(head,arr[i]);
        head=insertatlastnode(head,arr[i]);
    }
    cout<<endl;
    traverse(head);

return 0;
}