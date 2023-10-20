#include<iostream>
using namespace std;
struct node{
    int data;
    struct node * left;
    struct node * right;
};
struct node * createnode(int data){
    struct node * n=(struct node * )malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
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
void inorder(struct node * root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->data<<" ";
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
struct node * insert(struct node * root,int val){
    if(root == NULL){
        return createnode(val);
    }
    else if( val < root->data){
        root->left=insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
    }
    return root;
}
struct node * inorder1(struct node * root){
    root=root->left;
    while(root->right != NULL){
        root=root->right;
    }
    return root;
}
struct node * del(struct node * root, int del1){
    struct node * ipre;
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    if(del1 < root->data){
        root->left=del(root->left,del1);
    }
    else if(del1 > root->data){
        root->right=del(root->right,del1);
    }
    else{
        ipre=inorder1(root);
        root->data=ipre->data;
        root->left=del(root->left,ipre->data);
    }
    return root;
}
int main(){
    struct node * tree=NULL;
    int arr[100];
    int num;
    while(1){
        cin>>num;
        switch(num){
            case 1 : 
                int input;
                cin>>input;
                for(int i=0;i<input;i++){
                    cin>>arr[i];
                }
                tree=createtree(arr,0,input);
                break;
            case 2 : 
                postorder(tree);
                cout<<endl;
                break;
            case 3 : 
                preorder(tree);
                cout<<endl;
                break;
            case 4 : 
                inorder(tree);
                cout<<endl;
                break;
            case 5 :
                int insert1;
                cin>>insert1;
                insert(tree,insert1);
                cout<<endl;
                break;
            case 6 :
                int val1;
                cin>>val1;
                del(tree,val1);
                inorder(tree);
        }
    }
return 0;
}