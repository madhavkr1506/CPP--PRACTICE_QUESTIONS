#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
struct node {
    int data;
    struct node * left;
    struct node * right;
};
struct node * createnode(int data){
    struct node * n = (struct node * )malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void preorder(struct node * root){
    if(root != NULL){
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node * root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}
void inorder(struct node * root){
    if(root != NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
struct node * search(struct node * root, int key){
    if(root==NULL){
        return NULL;
    }
    if(key==root->data){
        return root;
    }
    else if (key<root->data){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}
struct node * inorderpredeccesor(struct node * root){
    root=root->left;
    while(root->right != NULL){
        root=root->right;
    }
    return root;
}
struct node * delete(struct node * root, int value){
    struct node * ipre;
    if(root==NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    if(value<root->data){
        root->left = delete(root->left,value);
    }
    else if(value > root->data){
        root->right = delete(root->right,value);
    }
    else{
        ipre=inorderpredeccesor(root);
        root->data=ipre->data;
        root->left = delete(root->left,ipre->data);
    }
    return root;
}

int main(){
    struct node * p = createnode(4);
    struct node * p1 = createnode(1);
    struct node * p2 = createnode(6);
    struct node * p3 = createnode(5);
    struct node * p4 = createnode(2);
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    preorder(p);
    printf("\n");
    postorder(p);
    printf("\n");
    inorder(p);
    printf("\n");
    // struct node * find=search(p,4);
    // if(find != NULL){
    //     printf("found %d",find->data);
    // }
    // else{
    //     printf("not found");
    // }
    delete(p,4);
    preorder(p);


return 0;
}