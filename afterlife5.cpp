// #include<iostream>
// using namespace std;
// struct node{
//     int data;
//     struct node * left;
//     struct node * right;
// };
// struct node * craetenode(int data){
//     struct node * n=(struct node*)malloc(sizeof(struct node));
//     n->data=data;
//     n->left=NULL;
//     n->right=NULL;
//     return n;
// }
// struct node * createtree(int arr[],int n,int i){
//     struct node * newnode=NULL;
//     if(i<n){
//         newnode=craetenode(arr[i]);
//         newnode->left=createtree(arr,n,2*i+1);
//         newnode->right=createtree(arr,n,2*i+2);
//     }
//     return newnode;
// }
// // void inorder(struct node * root){
// //     if(root != NULL){
// //         inorder(root->left);
// //         cout<<root->data<<" ";
// //         inorder(root->right);
// //     }
// // }
// void inorder(struct node *root){
//     if (root != NULL){
//         inorder(root->left);
//         if (root->data % 2 != 0) {
//             cout << root->data << " ";
//         }
//         inorder(root->right);
//     }
// }
// void preorder(struct node * root){
//     if(root != NULL){
//         cout<<root->data<<" ";
//         preorder(root->left);
//         preorder(root->right);
//     }
// }
// void postorder(struct node * root){
//     if(root != NULL){
//         postorder(root->left);;
//         postorder(root->right);
//         cout<<root->data<<" ";
//     }
// }
// struct node * insertnode(struct node * root,int data){
//     if(root==NULL){
//         return craetenode(data);
//     }
//     if(data==root->data){
//         return root;
//     }
//     else if(data<root->data){
//         root->left=insertnode(root->left,data);
//     }
//     else{
//         root->right=insertnode(root->right,data);
//     }
//     return root;
// }
// // void even(struct node * root,int level){
// //     if(root != NULL){
// //         if((level % 2) == 0){
// //             cout<<root->data<<" ";
// //         }
// //         even(root->left,level+1);
// //         even(root->right,level+1);
// //     }
// // }
// // void odd(struct node * root,int level){
// //     if(root != NULL){
// //         if((level % 2) != 0){
// //             cout<<root->data<<" ";
// //         }
// //         odd(root->left,level+1);
// //         odd(root->right,level+1);
// //     }
// // }
// void even(struct node * root){
//     if(root != NULL){
//         even(root->left);
//         if((root->data % 2) == 0){
//             cout<<root->data<<" ";
//         }
        
//         even(root->right);
//     }
// }
// void odd(struct node * root){
//     if(root != NULL){
//         odd(root->left);
//         if((root->data % 2) != 0){
//             cout<<root->data<<" ";
//         }
        
//         odd(root->right);
//     }
// }
// struct node * searchnode(struct node * root,int key,int level){
//     if(root==NULL){
//         return 0;
//     }
//     if(key==root->data){
//         cout << "Found " << key << " at position " << level << endl;
//         return level;
//     }
//     else if(key < root->data){
//         return searchnode(root->left,key,level+1);
//     }
//     else{
//         return searchnode(root->right,key,level+1);
//     }
// }
// int main(){
//     // struct node * root = NULL;
//     // int n;
//     // cin>>n;
//     // int val;
//     // // int level=1;
//     // // int arr[n];
//     // for(int i=0;i<n;i++){
//     //     cin>>val;
//     //     root=insertnode(root,val);

//     //     // cin>>arr[i];
//     // }
//     // // struct node * root = createtree(arr,n,0);
//     // // even(root,1);
//     // cout<<endl;
//     // // inorder(root);
//     // int dat;
//     // cin>>dat;
//     // int find = searchnode(root,dat,1);
//     // if(find != 0){
//     //     cout<<dat<<" "<<find;
//     // }
//     // else{
//     //     // printf("not found");
//     // }
//     struct node *root = NULL;
//     int n;
//     cin >> n;
//     int val;

//     for (int i = 0; i < n; i++) {
//         cin >> val;
//         root = insertnode(root, val);
//     }

//     int dat;
//     cin >> dat;
//     int level = searchnode(root, dat, 1);
//     if (level == -1) {
//         cout << "Not found" << endl;
//     }

// return 0;
// }

#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data) {
    struct node *n = new node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct node *insertNode(struct node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data == root->data) {
        return root;
    }
    else if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

int searchNode(struct node *root, int key, int level) {
    if (root == NULL) {
        return -1;
    }
    if (key == root->data) {
        cout << "Found " << key << " at position " << level << endl;
        return level;
    }
    else if (key < root->data) {
        int result = searchNode(root->left, key, level + 1);
        if (result != -1) {
            return result;
        }
    }
    else {
        int result = searchNode(root->right, key, level + 1);
        if (result != -1) {
            return result;
        }
    }
    return -1;
}

int main() {
    struct node *root = NULL;
    int n;
    cin >> n;
    int val;

    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insertNode(root, val);
    }

    int dat;
    cin >> dat;
    int level = searchNode(root, dat, 1);
    if (level == -1) {
        cout << "Not found" << endl;
    }

    return 0;
}
