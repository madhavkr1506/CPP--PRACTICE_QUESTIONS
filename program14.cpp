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

struct node * createtree(int arr[], int i,int n){
    struct node * newnode=NULL;
    if(i<n){
        newnode=createnode(arr[i]);
        newnode->left=createtree(arr,2*i+1,n);
        newnode->right=createtree(arr,2*i+2,n);
    }
    return newnode;
}

void postorder(struct node * root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

struct node * insertion(struct node * root, int value){
    if(root == NULL){
        return createnode(value);
    }
    else if(value < root->data){
        root->left = insertion(root->left,value);
    }
    else{
        root->right = insertion(root->right,value);
    }
    return root;
}

struct node * inorderpre(struct node * root){
    root=root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

struct node * deletion(struct node * root, int data){
    struct node * ipre;
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    if(data < root->data){
        root->left = deletion(root->left, data);
    }
    else if(data > root->data){
        root->right = deletion(root->right, data);
    }
    else{
        ipre=inorderpre(root);
        root->data=ipre->data;
        root->left = deletion(root->left,ipre->data);
    }
    return root;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    struct node * root=createtree(arr,0,n);
    postorder(root);
    cout<<endl;
    int value1;
    cin>>value1;
    insertion(root,value1);
    postorder(root);
    cout<<endl;
    int value2;
    cin>>value2;
    deletion(root,value2);
    postorder(root);
return 0;
}