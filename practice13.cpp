#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int data;
    int height;
    struct node * left;
    struct node * right;
};
int getheight(struct node * root){
    if(root == NULL){
        return 0;
    }
    else{
        return root->height;
    }
}
struct node * createnode(int data){
    struct node * n=(struct node *)malloc(sizeof(struct node ));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    n->height=1;
    return n;
}
void updateheight(struct node * root){
    if(root == NULL){
        return;
    }
    else{
        root->height=max(getheight(root->left),getheight(root->right)) + 1;
    }
}
int balancefactor(struct node * root){
    if(root == NULL){
        return 0;
    }
    else{
        return getheight(root->left) - getheight(root->right);
    }
}
struct node  * rightrotate(struct node * root){
    struct node * a=root->left;
    struct node * b=a->right;
    a->right=root;
    root->left=b;
    updateheight(root);
    updateheight(a);
    return a;
}
struct node * leftrotate(struct node * root){
    struct node * a=root->right;
    struct node * b=a->left;
    a->left=root;
    root->right=b;
    updateheight(root);
    updateheight(a);
    return a;
}
struct node * insertion(struct node * root, int data){
    if(root == NULL){
        return createnode(data);
    }
    if(data == root->data){
        return root;
    }
    else if(data < root->data){
        root->left = insertion(root->left,data);
    }
    else{
        root->right = insertion(root->right,data);
    }
    updateheight(root);
    int balance=balancefactor(root);
    if(balance > 1 && data > root->left->data){
        root->left=leftrotate(root->left);
        return rightrotate(root);
    }
    if(balance > 1 && data < root->left->data){
        return rightrotate(root);
    }
    if(balance < -1 && data < root->right->data){
        root->right=rightrotate(root->right);
        return leftrotate(root);
    }
    if(balance < -1 && data > root->right->data){
        return leftrotate(root);
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
struct node * deletion(struct node * root,int data){
    struct node * ipre;
    if(root==NULL){
        return NULL;
    }
    if(root->left == NULL || root->right == NULL){
        free(root);
        return NULL;
    }
    if(data < root->data){
        root->left = deletion(root->left,data);
    }
    else if(data > root->data){
        root->right = deletion(root->right,data);
    }
    else{
        ipre=inorderpre(root);
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
    struct node * root=NULL;
    int choice;
    while(1){
        cin>>choice;
        switch(choice){
            case 1 : int num;
            cin>>num;
            for(int i=0;i<num;i++){
                int data;
                cin>>data;
                root=insertion(root,data);
            }
            break;
            case 2 : inorder(root);
            cout<<endl;
            break;
            case 3 : 
            int data;
            cin>>data;
            root=deletion(root,data);
            break;
            default : 
            exit(0);
            break; 
        }
    }
return 0;
}
