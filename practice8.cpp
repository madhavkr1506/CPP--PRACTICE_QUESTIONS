#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *next;
};
class nodeoperation{
    public:
    void pushnode(class node** head_ref,int data_var){
        class node *newnode = new node();
        newnode->data=data_var;
        newnode->next = *head_ref;
        *head_ref = newnode;
    }
};

int main(){
class node *head=NULL;
    class nodeoperation *temp=new nodeoperation();
    for(int i=5;i>0;i--){
        temp->pushnode(&head,i);
    }
    vector<int>v;
    while(head!=NULL){
        v.push_back(head->data);
        head=head->next;
    }
    cout<<"middle value of the linked list is : ";
    cout<<v[v.size()/2]<<endl;
return 0;
}
