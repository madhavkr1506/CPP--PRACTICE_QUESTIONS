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
struct node * createtree(int arr[],int num,int i){
    struct node * newnode=nullptr;
    if(i<num){
        newnode=createnode(arr[i]);
        newnode->left=createtree(arr,num,2*i+1);
        newnode->right=createtree(arr,num,2*i+2);
    }
    return newnode;
}
struct node *insertnode(struct node * root,int data){
    if(root==NULL){
        return createnode(data);
    }
    if(data==root->data){
        return root;
    }
    else if(data<root->data){
        root->left=insertnode(root->left,data);
    }
    else{
        root->right=insertnode(root->right,data);
    }
    return root;
}
void odd_depth(struct node * root,int position){
    if(root==NULL){
        return;
    }
    if(position % 2 != 0){
        cout<<root->data<<" ";
    }
    odd_depth(root->left,position+1);
    odd_depth(root->right,position+1);
}
void inorder(struct node * root){
    if(root != NULL){
        inorder(root->left);
        // if(root->data % 2 != 0){
        cout<<root->data<<" ";
        // }
        inorder(root->right);
    }
}
struct node * search(struct node *root,int data,int position){
    if(root==NULL){
        return 0;
    }
    if(data==root->data){
        cout<<data<<" found at "<<position<<endl;
        return root;
    }
    else if(data<root->data){
        return search(root->left,data,position+1);
    }
    else{
        return search(root->right,data,position+1);
    }
}
int smallestgreater(struct node * root,int value){
    int store=-1;
    while(root != NULL){
        if(root->data <= value){
            root=root->right;
        }else{
            store=root->data;
            root=root->left;
        }
    }
    return store;
}
int getheight(struct node * root){
    if(root==NULL){
        return 0;
    }
    int left=getheight(root->left);
    int right=getheight(root->right);
    return max(left, right) + 1;
}
struct node * packet(struct node * root){
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
struct node *delete1(struct node * root,int data){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    if(data < root->data){
        root->left=delete1(root->left,data);
    }
    else if(data > root->data){
        root->right=delete1(root->right,data);
    }
    else{
        struct node * ipre=packet(root);
        root->data=ipre->data;
        root->left=delete1(root->left,ipre->data);
    }
    return root;
}
int main(){
    struct node * root=nullptr;
    int num;
    cin>>num;
    // int arr[num];
    for(int i=0;i<num;i++){
        int data;
        cin>>data;
        root=insertnode(root,data);
        // cin>>arr[i];
    }
    // root=createtree(arr,num,0);
    // odd_depth(root,1);
    // inorder(root);
    int data;
    cin>>data;
    struct node * find=search(root,data,0);
    // int small=smallestgreater(root,data);
    // cout<<small;
    // int len=getheight(root);
    // cout<<len;
    // struct node * key=packet(root);

    // delete1(root,key->data);
    // inorder(root);
return 0;

}