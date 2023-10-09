#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
struct tree{
    int data;
    struct tree * left;
    struct tree * right;
};
struct tree * createnode(int data){
    struct tree * n = (struct tree *)malloc(sizeof(struct tree ));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void preorder(struct tree * root){
    if(root != NULL){
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct tree * root){
    if(root != NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
void postorder(struct tree * root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}
struct tree * inorderprecedence(struct tree * root){
    root=root->left;
    while(root->right != NULL){
        root=root->right;
    }
    return root;
}
struct tree * deletenode( struct tree * root,int value){
    struct tree * ipre;
    if(root == NULL){
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
    ipre = inorderprecedence(root);
    root->data=ipre->data;
    root->left = deletenode(root->left,ipre->data);
    }
    return root;
}
void insertnode(struct tree * root,int value){
    struct tree * prev=NULL;
    while(root != NULL){
        prev=root;
        if(value == root->data){
            printf("cannot insert \n");
            return;
        }
        else if(value < root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    struct tree * new = createnode(value);
    if(value < prev->data){
        prev->left = new;
    }
    else{
        prev->right = new;
    }
}

struct tree * searchnode(struct tree * root ,int value){
    if(root == NULL){
        return NULL;
    }
    if(value == root->data){
        return root;
    }
    else if(value < root->data){
        return searchnode(root->left,value);
    }
    else{
        return searchnode(root->right,value);
    }
}

int maxdepth(struct tree * root){
    if(root == NULL){
        return 0;
    }
    else{
        int ldepth = maxdepth(root->left);
        int rdepth = maxdepth(root->right);
        if(ldepth > rdepth){
            return (ldepth + 1);
        }
        else{
            return (rdepth + 1);
        }
    }
}
int main(){
    struct tree * p=createnode(11);
    struct tree * p1=createnode(8);
    struct tree * p2=createnode(15);
    struct tree * p3=createnode(14);
    struct tree * p4=createnode(21);

    p->left=p1;
    p->right=p2;
    p2->left=p3;
    p2->right=p4;
    // inorder(p);
    // printf("\n");
    postorder(p);
    printf("\n");
    // preorder(p);
    // printf("\n");
    // deletenode(p,21);
    // insertnode(p,23);
    // printf("%d",p->right->right->right->data);
    // struct tree * find = searchnode(p,5);
    // if(find != NULL){
    //     printf("found\n");
    // }
    // else{
    //     printf("not found\n");
    // }
    // inorder(p);
    // printf("\n");
    // postorder(p);
    // printf("\n");
    printf("%d",maxdepth(p));

return 0;
}