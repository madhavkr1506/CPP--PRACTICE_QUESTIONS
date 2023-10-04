#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
struct stack{
    int data;
    struct stack * left;
    struct stack * right;
};

struct stack * createnode(int data){
    struct stack * n = (struct stack *)malloc(sizeof(struct stack ));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void preorder(struct stack * root){
    if(root != NULL){
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct stack * root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}

void inorder(struct stack * root){
    if(root != NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
struct stack * search(struct stack * root, int key){
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

void insertion (struct stack * root, int value){
    struct stack * prev = NULL;
    while(root != NULL){
        prev = root;
        if(value == root->data){
            printf("you cannot insert %d here",value);
            return;
        }
        else if(value < root->data){
            root = root->left;
        }
        else{
            root=root->right;
        }
    }
    struct stack * new = createnode(value);
    if(value < prev->data){
        prev->left=new;
    } 
    else{
        prev->right=new;
    }
}

struct stack * inorderpre(struct stack * root){
    root=root->left;
    while(root->right != NULL){
        root=root->right;
    }
    return root;
}

struct stack * deletenode(struct stack * root, int value){
    struct stack * ipre;
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL &&  root->right == NULL){
        free(root);
        return NULL;
    }
    if(value < root->data){
        // root->left = deletenode(root->left,value);
        return deletenode(root->left,value);
    }
    else if (value > root->data){
        // root->right = deletenode(root->right,value);
        return deletenode(root->right,value);
    }
    else{
        ipre = inorderpre(root);
        root->data=ipre->data;
        // root->left = deletenode(root->left,ipre->data);
        return deletenode(root->left,ipre->data);
    }
    return root;
} 
int main(){
    struct stack * p = createnode(11);
    struct stack * p1 = createnode(7);
    struct stack * p2 = createnode(15);
    struct stack * p3 = createnode(5);
    struct stack * p4 = createnode(9);

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
    struct stack * find = search(p,16);
    if(find != NULL){
        printf("found %d",find->data);
    }
    else{
        printf("not found");
    }
    printf("\n");
    insertion(p,17);
    printf("%d",p->right->right->data);
    printf("\n");
    printf("%d",p->right->data);
    printf("\n");
    inorder(p);
    printf("\n");
    deletenode(p,17);
    printf("\n");
    inorder(p);

return 0;
}