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

void reverse(struct node * ptr){
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}

void bubblesort(struct node * head){
    int i, swapped;
    struct node * start;
    struct node * finish=NULL;
    if(head == NULL){
        return;
    }
    do{
        swapped=0;
        start=head;
        while(start->next != finish){
            if(start->data > start->next->data){
                swap(start->data,start->next->data);
                swapped=1;
            }
            start=start->next;
        }
        finish=start;
    }while(swapped);
}

void even(struct node * head){
    struct node * current =head;
    while(current != NULL){
        if((current->data) % 2 == 0 ){
            cout<<current->data<<" ";
        }
        current=current->next;
    }
}

void odd(struct node * head){
    struct node * current =head;
    while(current != NULL){
        if((current->data) % 2 != 0){
            cout<<current->data<<" ";
        }
        current=current->next;
    }
}
int main(){

    int num;
    cin>>num;
    int arr[num];
    int i;
    for(i=0;i<num;i++){
        cin>>arr[i];
    }
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

    head->data=arr[0];
    head->next=second;
    head->prev=NULL;

    second->data=arr[1];
    second->next=third;
    second->prev=head;

    third->data=arr[2];
    third->next=fourth;
    third->prev=second;

    fourth->data=arr[3];
    fourth->next=fifth;
    fourth->prev=third;

    fifth->data=arr[4];
    fifth->next=NULL;
    fifth->prev=fourth;

    // traverse(head);
    // cout<<endl;
    // reverse(head);
    // cout<<endl;
    // bubblesort(head);
    // reverse(head);
    // cout<<endl;
    // struct node *current =head;
    // while(current->next != NULL){
    //     current=current->next;
    // }
    // cout<<current->data;
    
    // cout<<endl;
    // int size=1;
    // struct node *lenght=head;
    // while(lenght->next != NULL){
    //     size++;
    //     lenght=lenght->next;
    // }
    // cout<<size;

    even(head);
    bubblesort(head);
    odd(head);




return 0;
}