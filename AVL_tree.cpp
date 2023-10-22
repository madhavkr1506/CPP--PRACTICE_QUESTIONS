#include<iostream>
#include<algorithm>
using namespace std;
struct node {
    int data;
    struct node * left;
    struct node * right;
    int height;
};
int getheight(struct node * root){
    if(root == NULL){
        return 0;
    }
    else{
        return root->height;
    }
}
int getbalancefactor(struct node * root){
    if(root == NULL){
        return 0;
    }
    else{
        return getheight(root->left) - getheight(root->right);
    }
}
struct node * createnode(int data){
    struct node * n=(struct node *)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    n->height=1;
    return n;
}
struct node * rightrotate(struct node * root){
    struct node * a=root->left;
    struct node * b=a->right;
    a->right=root;
    root->left=b;
    root->height=max(getheight(root->right),getheight(root->left)) + 1;
    a->height=max(getheight(a->right),getheight(a->left)) + 1;
    return a;
}
struct node * rotateleft(struct node * root){
    struct node * a=root->right;
    struct node * b=a->left;
    a->left=root;
    root->right=b;
    root->height=max(getheight(root->right),getheight(root->left)) + 1;
    a->height=max(getheight(a->right),getheight(a->left)) + 1;
    return a;
}
void preorder(struct node * root){
    if(root != NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node * root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
struct node * insert(struct node * root,int key){
    if (root == NULL) {
        return createnode(key);
    }
    if(key == root->data){
        return root;
    }
    else if(key < root->data){
        root->left=insert(root->left,key);
    }
    else{
        root->right=insert(root->right,key);
    }
    root->height=max(getheight(root->left),getheight(root->right)) + 1;
    int balance=getbalancefactor(root);
    // left left case
    if(balance > 1 && key < root->left->data){
        return rightrotate(root);
    }
    // left right case
    if(balance > 1 && key > root->left->data){
        root->left = rotateleft(root->left);
        return rightrotate(root);
    }
    // right right case
    if(balance < -1 && key > root->right->data){
        return rotateleft(root);
    }
    // right left case
    if(balance < -1 && key < root->right->data){
        root->right = rightrotate(root->right);
        return rotateleft(root);
    }
    return root;
}
int main(){
    struct node * root = NULL;
 
 
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preorder(root);
    cout<<endl;
    inorder(root);
    return 0;
}
