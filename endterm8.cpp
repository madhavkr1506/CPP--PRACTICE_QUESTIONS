#include<iostream>
using namespace std;
struct node {
    int data;
    struct node * left;
    struct node * right;
};
struct node * createnode(int data){
    struct node * n=(struct node *)malloc(sizeof(struct node ));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
struct node * createtree(int arr[],int n,int i){
    struct node * newnode = nullptr;
    if(i<n){
        newnode=createnode(arr[i]);
        newnode->left=createtree(arr,n,2*i+1);
        newnode->right=createtree(arr,n,2*i+2);
    }
    return newnode;
}
struct node *search(struct node * root,int data,int position){
    if(root==NULL){
        return 0;
    }
    if(data==root->data){
        cout<<"data "<<data<<" is present at this "<<position<<" node.\n";
        return root;
    }
    else if(data < root->data){
        return search(root->left,data,position+1);
    }
    else{
        return search(root->right,data,position+1);
    }
}

void insertion(struct node * root,int data){
    struct node * prev=NULL;
    while(root != NULL){
        prev=root;
        if(data == root->data){
            cout<<"you cant insert same element \n";
            return;
        }
        else if(data < root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    struct node * new1=createnode(data);
    if(data < prev->data){
        prev->left=new1;
    }
    else{
        prev->right=new1;
    }

}

struct node * insertnode(struct node* root,int data){
    if(root == NULL){
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

struct node * packet(struct node * root){
    root=root->left;
    while(root->right != NULL){
        root=root->right;
    }
    return root;
}
struct node * deletion(struct node * root,int data){
    struct node * ipre;
    if(root==NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    if(data < root->data){
        root->left=deletion(root->left,data);
    }
    else if(data > root->data){
        root->right=deletion(root->right,data);
    }
    else{
        ipre=packet(root);
        root->data=ipre->data;
        root->left=deletion(root->left,ipre->data);
    }
    return root;

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

int main(){

    // this is for createtree structure

    // struct node * root=nullptr;
    // int num;;
    // cin>>num;
    // int arr[num];
    // for(int i=0;i<num;i++){
    //     cin>>arr[i];
    // }
    // root=createtree(arr,num,0);
    // inorder(root);
    // int ele;
    // cin>>ele;
    // struct node * find=search(root,ele,1);
    // if(!find){
    //     cout<<"element not present in binary search tree\n";
    // }

    // this is for insertion 

    // struct node * root=createnode(0);
    // int num;
    // cin>>num;
    // for(int i=0;i<num;i++){
    //     int data;
    //     cin>>data;
    //     insertion(root,data);
    // }

    // this is for insertnode 

    // struct node * root=nullptr;
    // int num;
    // cin>>num;
    // for(int i=0;i<num;i++){
    //     int data;
    //     cin>>data;
    //     root=insertnode(root,data);
    // }



    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    int ele;
    cin>>ele;

    deletion(root,ele);

    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;

return 0;
}