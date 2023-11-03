#include<iostream>
using namespace std;
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
struct node * insert(struct node * root,int data){
    if(root==nullptr){
        return createnode(data);
    }
    if(data==root->data){
        return root;
    }
    else if(data < root->data){
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
}
int findsmallgraetest(struct node * root,int data){
    int store=-1;
    while(root != NULL){
        if(data >= root->data){
            root=root->right;
        }
        else{
            store=root->data;
            root=root->left;
        }
    }
    return store;
}
struct node * search(struct node * root,int value,int position){
    if(root==NULL){
        return 0;
    }
    if(value == root->data){
        cout<<"value "<<value<<" at "<<position<<endl;
        return root;
    }
    else if(value < root->data){
        return search(root->left,value,position + 1);
    }
    else{
        return search(root->right,value,position + 1);
    }
}
int inorderprecedence(struct node * root){
    while(root->right!=NULL){
        root=root->right;
    }
    return root->data;
}
struct node * deletenode(struct node * root,int data){
    struct node * ipre;
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    if(data < root->data){
        root->left=deletenode(root->left,data);
    }
    else if(data > root->data){
        root->right=deletenode(root->right,data);
    }
    else{
        ipre=createnode(inorderprecedence(root->left));
        root->data=ipre->data;
        root->left=deletenode(root->left,ipre->data);
    }
    return root;
}
void inorder(struct node * root){
    if(root!= NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
int main(){
    struct node * tree=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        tree=insert(tree,val);
    }
    // int num;
    // cin>>num;
    // int smallestgreater=findsmallgraetest(tree,num);7
    // cout<<smallestgreater;
    // struct node * find=search(tree,num,1);
    // if(!find){
    //     cout<<"not found in BST\n";
    // }
    int maxele=inorderprecedence(tree);
    tree=deletenode(tree,maxele);
    inorder(tree);

return 0;
}