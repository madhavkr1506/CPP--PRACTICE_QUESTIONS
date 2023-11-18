#include<iostream>
using namespace std;
struct node{
    int data;
    struct node * left;
    struct node * right;
};
struct node * createnode(int data){
    struct node * n=(struct node * )malloc(sizeof(struct node ));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
struct node * createtree(int arr[],int n,int i){
    struct node * newnode=nullptr;
    if(i<n){
        newnode=createnode(arr[i]);
        newnode->left=createtree(arr,n,2*i+1);
        newnode->right=createtree(arr,n,2*i+2);
    }
    return newnode;
}
struct node * searchnode(struct node * root,int data,int position){
    if(root == NULL){
        return 0;
    }
    if(data == root->data){
        cout<<data<<" found at "<<position<<endl;
        return root;
    }
    else if(data < root->data){
        return searchnode(root->left,data,position);
    }
    else{
        return searchnode(root->right,data,position);
    }
}
struct node * insertnode(struct node * root,int data){
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
// struct node * packet(struct node * root){
//     // root=root->left;
//     while(root->right!=NULL){
//         root=root->right;
//     }
//     return root;
// }
struct node * packet(struct node * root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
struct node * deletenode(struct node * root,int data){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
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
        struct node * ipre=packet(root);
        root->data=ipre->data;
        root->left=deletenode(root->left,ipre->data);
    }
    return root;
}
void inorder(struct node * root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void preorder(struct node * root){
    if(root != NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node * root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
// struct node * deleteinrange(struct node * root,int minrange,int maxrange){
//     if(root == NULL){
//         return NULL;
//     }
//     root->left=deleteinrange(root->left,minrange,maxrange);
//     root->right=deleteinrange(root->right,minrange,maxrange);
//     if(root->data <= minrange || root->data >= maxrange){
//         if(root->left == NULL && root->right == NULL){
//             free(root);
//             return NULL;
//         }
//         else if(root->right == NULL){
//             struct node * temp=root->left;
//             free(root);
//             return temp;
//         }
//         else if(root->left == NULL){
//             struct node * temp=root->right;
//             free(root);
//             return temp;
//         }
//         else{
//             struct node * ipre=packet(root);
//             root->data=ipre->data;
//             root->left=deleteinrange(root->left,ipre->data,ipre->data);
//         }
//     }
//     return root;
// }




int main(){
    struct node * root=nullptr;
    int num;
    cin>>num;
    int arr[num];
    for(int i=0;i<num;i++){
        cin>>arr[i];
        // int data;
        // cin>>data;
        // root=insertnode(root,data);
    }
    root=createtree(arr,num,0);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    // int delete1;
    // cin>>delete1;
    // root=deletenode(root,delete1);
    // inorder(root);
    // cout<<endl;
    // int search;
    // cin>>search;
    // struct node * find=searchnode(root,search,1);
    // cout<<endl;

    // int mini;
    // cin>>mini;
    // int maxi;
    // cin>>maxi;
    // root=deleteinrange(root,mini,maxi);

    struct node * ele=packet(root);
    deletenode(root,ele->data);

    inorder(root);

return 0;
}