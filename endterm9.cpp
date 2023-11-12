#include<iostream>
using namespace std;
struct node{
    int data;
    struct node * left;
    struct node * right;
};
struct node * createnode (int data){
    struct node * n=(struct node *)malloc(sizeof(struct node ));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
struct node * insertnode(struct node * root,int data){
    if(root==NULL){
        return createnode(data);
    }
    if(data==root->data){
        return root;
    }
    else if(data < root->data){
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
// struct node * deletenode(struct node * root,int minrange,int maxrange){
//     if(root==NULL){
//         return 0;
//     }
//     root->left=deletenode(root->left,minrange,maxrange);
//     root->right=deletenode(root->right,minrange,maxrange);
//     if(root->data >= minrange && root->data <= maxrange){
//         struct node * ipre;
//         if(root->left == NULL && root->right== NULL){
//             free(root);
//             return NULL;
//         }
//         ipre=packet(root);
//         root->data=ipre->data;
//         root->left=deletenode(root->left,ipre->data,ipre->data);
//     }
//     return root;
// }
// struct node * deletenode(struct node * root, int minrange, int maxrange) {
//     if (root == NULL) {
//         return NULL;
//     }
    
//     root->left = deletenode(root->left, minrange, maxrange);
//     root->right = deletenode(root->right, minrange, maxrange);

//     if (root->data >= minrange && root->data <= maxrange) {
//         struct node *ipre;
//         if (root->left == NULL && root->right == NULL) {
//             free(root);
//             return NULL;
//         } else if (root->left == NULL) {
//             struct node *temp = root->right;
//             free(root);
//             return temp;
//         } else if (root->right == NULL) {
//             struct node *temp = root->left;
//             free(root);
//             return temp;
//         } else {
//             ipre = packet(root);
//             root->data = ipre->data;
//             root->left = deletenode(root->left, ipre->data, ipre->data);
//         }
//     }

//     return root;
// }

struct node * deletenode(struct node * root,int minirange,int maxrange){
    struct node * ipre;
    if(root==NULL){
        return NULL;
    }
    
    root->left=deletenode(root->left,minirange,maxrange);
    root->right=deletenode(root->right,minirange,maxrange);
    if(root->data<=minirange || root->data>=maxrange){
        if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    ipre=packet(root);
    root->data=ipre->data;
    root->left=deletenode(root->left,ipre->data,ipre->data);
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
int main(){
    struct node * root=nullptr;
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        int data;
        cin>>data;
        root=insertnode(root,data);
    }
    inorder(root);
    cout<<endl;
    int mini;
    cin>>mini;
    int maxi;
    cin>>maxi;
    deletenode(root,mini,maxi);
    inorder(root);
return 0;
}