#include<iostream>
#include<algorithm>
using namespace std;
struct node {
    int data;
    struct node * left;
    struct node * right;
    int height;
};
struct node * createnode(int data){
    struct node * n=(struct node * )malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    n->height=1;
    return n;
}
int getheight(struct node * root){
    if(root == NULL){
        return 0;
    }
    else{
        return root->height;
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

struct node * rightrotate(struct node * root){
    struct node * a=root->left;
    struct node * b=a->right;
    a->right=root;
    root->left=b;
    root->height=max(getheight(root->left),getheight(root->right)) + 1;
    a->height=max(getheight(a->left),getheight(a->right)) + 1;
    return a;
}
struct node * leftrotate(struct node * root){
    struct node * a=root->right;
    struct node * b=a->left;
    a->left=root;
    root->right=b;
    root->height=max(getheight(root->left),getheight(root->right)) + 1;
    a->height=max(getheight(a->left),getheight(a->right)) + 1;
    return a;
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
node* findMinNode(node* root) {
    if (root->left != nullptr)
        return findMinNode(root->left);
    return root;
}

node* deleteNode(node* root, int data) {
    if (root == nullptr) return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            node* temp = root->left ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }
            delete temp;
        } else {
            node* temp = findMinNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == nullptr) return root;
    root->height=max(getheight(root->left),getheight(root->right)) + 1;
    int balance=balancefactor(root);
    if(balance > 1 && data > root->left->data){
        root->left=leftrotate(root->left);
        return rightrotate(root);
    }
    if(balance > 1 && data < root->left->data){
        return rightrotate(root);
    }
    if(balance < -1 && data > root->right->data){
        return leftrotate(root);
    }
    if(balance < -1 && data < root->right->data){
        root->right=rightrotate(root->right);
        return leftrotate(root);
    }
    return root;

}
struct node * search(struct node * root,int data){
    if(root == NULL){
        return 0;
    }
    if(data == root->data){
        return root;
    }
    else if(data < root->data){
        return search(root->left,data);
    }
    else{
        return search(root->right,data);
    }
}
struct node * insert(struct node * root,int data){
    if(root==NULL){
        return createnode(data);
    }
    if(data == root->data){
        return root;
    }
    else if(data < root->data){
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }
    root->height=max(getheight(root->left),getheight(root->right)) + 1;
    int balance=balancefactor(root);
    if(balance > 1 && data > root->left->data){
        root->left=leftrotate(root->left);
        return rightrotate(root);
    }
    if(balance > 1 && data < root->left->data){
        return rightrotate(root);
    }
    if(balance < -1 && data > root->right->data){
        return leftrotate(root);
    }
    if(balance < -1 && data < root->right->data){
        root->right=rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
}
int main(){
    struct node * root = NULL;
    int num;
    int data;
    while(true){
        cin>>num;
        if(num == 1){
            cin>>data;
            root=insert(root,data);
        }
        else if (num == 2) {
            cin >> data;
            root = deleteNode(root, data);
            cout << "Preorder Traversal after deletion: ";
            preorder(root);
            cout << endl;
        }

        else if(num == 3){
            preorder(root);
            cout<<endl;
        }
    }
return 0;
}