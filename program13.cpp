#include<iostream>
using namespace std;
struct node {
    int data;
    struct node * left;
    struct node * right;
};

struct node * createnode(int data){
    struct node * n = (struct node * )malloc(sizeof(struct node ));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
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

void preorder(struct node * root){
    if(root != NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}



struct node * createtree(int arr[],int i,int n){
    struct node * newnode =NULL;
    if(i<n){
        newnode=createnode(arr[i]);
        newnode->left=createtree(arr,2*i+1,n);
        newnode->right=createtree(arr,2*i+2,n);
    }
    return newnode;
}

struct node * insertion (struct node * root, int value){
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
        root=root->right;
    }
    return root;
}

struct node * deletenode(struct node * root, int value){
    struct node * ipre;
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL &&  root->right == NULL){
        free(root);
        return NULL;
    }
    if(value < root->data){
        root->left = deletenode(root->left,value);
    }
    else if (value > root->data){
        root->right = deletenode(root->right,value);
    }
    else{
        ipre = inorderpre(root);
        root->data=ipre->data;
        root->left = deletenode(root->left,ipre->data);
    }
    return root;
}

int main(){
    int num;
    cin>>num;
    int arr[num];
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }
    struct node * root=createtree(arr,0,num);
    postorder(root);
    cout<<endl;
    // inorder(root);
    int value;
    cin>>value;
    root=insertion(root,value);
    postorder(root);
    cout<<endl;
    int value1;
    cin>>value1;
    deletenode(root,value1);
    postorder(root);

return 0;
}