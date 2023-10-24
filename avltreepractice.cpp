#include<iostream>
#include<algorithm>
using namespace std;
struct node {
    int data;
    struct node * left;
    struct node * right;
    int height;
};
struct node * creatnode(int data){
    struct node * n=(struct node *)malloc(sizeof(struct node ));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    n->height=1;
    return n;
}
int getheight(struct node * root){
    if(root == NULL){
        return 0;
    }
    else{
        return root->height;
    }
}
int balancefactor(struct node * root){
    if(root == NULL){
        return 0;
    }
    else{
        return getheight(root->right) - getheight(root->left);
    }
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
void postorder(struct node * root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

void updateheight(struct node * root){
    if(root == NULL){
        return;
    }
    else{
        root->height=max(getheight(root->left),getheight(root->right)) + 1;
    }
}
struct node * leftrotate(struct node * root){
    struct node * a=root->right;
    struct node * b=a->left;
    a->left=root;
    root->right=b;
    // root->height=max(getheight(root->right),getheight(root->left)) + 1;
    // a->height=max(getheight(a->right),getheight(a->left)) + 1;
    updateheight(root);
    updateheight(a);
    return a;
}
struct node * rightrotate(struct node * root){
    struct node * a = root->left;
    struct node * b = a->right;
    a->right=root;
    root->left=b;
    // root->height=max(getheight(root->right),getheight(root->left)) + 1;
    // a->height=max(getheight(a->right),getheight(a->left)) + 1;
    updateheight(root);
    updateheight(a);
    return a;
}
struct node * insert(struct node * root, int data){
    if(root == NULL){
        return creatnode(data);
    }
    if(data == root->data){
        return root;
    }
    else if(data < root->data){
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }
    // root->height=max(getheight(root->right),getheight(root->left)) + 1;
    updateheight(root);
    int balance=balancefactor(root);
    if(balance > 1 && data > root->right->data){
        return leftrotate(root);
    }
    if(balance > 1 && data < root->right->data){
        root->right=rightrotate(root->right);
        return leftrotate(root);
    }
    if(balance < -1 && data < root->left->data){
        return rightrotate(root);
    }
    if(balance < -1 && data > root->left->data){
        root->left=leftrotate(root->left);
        return rightrotate(root);
    }
    return root;
}
struct node * search(struct node * root,int key){
    if (root == NULL){
        return 0;
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
struct node * deletion(struct node * root,int val){
    struct node * ipre;
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    if(val < root->data){
        root->left = deletion(root->left,val);
    }
    else if (val > root->data){
        root->right = deletion(root->right,val);
    }
    else{
        ipre=inorderpre(root);
        root->data=ipre->data;
        root->left=deletion(root->left,ipre->data);
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
    cout<<endl;
    struct node * find=search(root,1);
    if(find != NULL){
        cout<<"found";
    }
    else{
        cout<<"not find\n";
    }
    cout<<endl;
    root=deletion(root,4);
    inorder(root);
return 0;
}