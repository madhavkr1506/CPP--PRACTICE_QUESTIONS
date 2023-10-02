#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
struct node {
    int data;
    struct node * left;
    struct node * right;
};
struct node * createnode(int data){
    struct node * n=(struct node *)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
int main(){
    /*struct node * p=(struct node * )malloc(sizeof(struct node));
    p->data=4;
    p->left=NULL;
    p->right=NULL;

    struct node *p1 = (struct node *)malloc(sizeof(struct node));
    p1->data=1;
    p1->left=NULL;
    p1->right=NULL;

    struct node * p2=(struct node *)malloc(sizeof(struct node));
    p2->data=6;
    p2->left=NULL;
    p2->right=NULL;

    p->left=p1;
    p->right=p2;
    */
   struct node * p=createnode(2);
   struct node * p1=createnode(1);
   struct node * p2=createnode(4);
   
   p->left=p1;
   p->right=p2;
return 0;
}