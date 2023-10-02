#include<bits/stdc++.h>
using namespace std;
struct node{
    int key;
    struct node* next;
};
node* newnode(int key){
    node* temp = new node;
    temp->key = key;
    temp->next = NULL;
    return temp;
}
    
int main(){
    node* a=newnode(5);
    a->next=newnode(10);
    a->next->next=newnode(15);
    a->next->next->next=newnode(40);

    node* b=newnode(2);
    b->next=newnode(3);
    b->next->next=newnode(20);

    vector<int>v;
    while(a!=NULL){
        v.push_back(a->key);
        a=a->next;
    }
    while(b!=NULL){
        v.push_back(b->key);
        b=b->next;
    }
    sort(v.begin(),v.end());
    node* result=newnode(-1);
    node* temp=result;
    for(int i=0;i<v.size();i++){
        result->next=newnode(v[i]);
        result=result->next;
    }
    temp=temp->next;
    cout<<"Resultant merge linked list is : "<<endl;
    while(temp!=NULL){
        cout<<temp->key<<" ";
        temp=temp->next;
    }
return 0;
}