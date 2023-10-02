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
    struct node * n = (struct node *)malloc(sizeof(struct node));
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
struct node * search(struct node * root,int key){
    if(root == NULL){
        return NULL;
    }
    if(key == root->data){
        return root;
    }
    else if(key < root->data){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}
struct node * inorderpre(struct node * root){
    root=root->left;
    while(root->right != NULL){
        root=root->right;
    }
    return root;
}
struct node * deletenode(struct node * root, int value ){
    struct node * ipre;
    if (root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    if(value < root->data){
        root->left = deletenode(root->left,value);
    }
    else if(value > root->data){
        root->right = deletenode(root->right,value);
    }
    else{
        ipre = inorderpre(root);
        root->data=ipre->data;
        root->left = deletenode(root->left,ipre->data);
    }
    return root;
}
void insertnode(struct node * root,int key){
    struct node * prev = NULL;
    while(root != NULL){
        prev = root;
        if(key == root->data){
            printf("cannot insert %d, it is already in bst\n");
            return;
        }
        else if(key < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    struct node * new = createnode(key);
    if(key < prev->data){
        prev->left = new;
    }
    else{
        prev->right = new;
    }
}
int main(){
    struct node * p = createnode(5);
    struct node * p1 = createnode(3);
    struct node * p2 = createnode(6);
    struct node * p3 = createnode(1);
    struct node * p4 = createnode(4);
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    printf("preorder = ");
    preorder(p);
    printf("\n");
    printf("postorder = ");
    postorder(p);
    printf("\n");
    printf("inorder = ");
    inorder(p);
    printf("\n");
    struct node * find = search(p,4);
    if(find != NULL){
        printf("found = %d",find->data);
    }
    else{
        printf("not found");
    }
    printf("\n");
    deletenode(p,5);
    printf("preorder after deletion = ");
    preorder(p);
    printf("\n");
    printf("postorder after deletion = ");
    postorder(p);
    printf("\n");
    printf("inorder after deletion = ");
    inorder(p);

    insertnode(p,16);
    printf("%d",p->right->right->data);
return  0;
}