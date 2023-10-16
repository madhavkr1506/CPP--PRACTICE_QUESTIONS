#include<iostream>
#include<algorithm>
using namespace std;
struct node{
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

void posttraversal(struct node * root){
    if(root != NULL){
        posttraversal(root->left);
        posttraversal(root->right);
        cout<<root->data<<" ";
    }
}
void pretraversal(struct node * root){
    if(root != NULL){
        cout<<root->data<<" ";
        pretraversal(root->left);
        pretraversal(root->right);
    }
}
void intraversal(struct node * root){
    if(root != NULL){
        intraversal(root->left);
        cout<<root->data<<" ";
        intraversal(root->right);
    }
}
struct node *search(struct node * root, int key){
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
struct node * inorderpre(struct node * root){
    root=root->left;
    while(root->right != NULL){
        root=root->right;
    }
    return root;
}
struct node * deletenode(struct node * root,int value){
    struct node * ipre;
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    if(value<root->data){
        root->left = deletenode(root->left,value);
    }
    else if(value > root->data){
        root->right = deletenode(root->right,value);
    }
    else{
        ipre=inorderpre(root);
        root->data=ipre->data;
        root->left=deletenode(root->left,ipre->data);
    }
    return root;
}
void insertnode(struct node * root,int key){
    struct node * prev=NULL;
    while(root != NULL){
        prev=root;
        if(key == root->data){
            cout<<"you cannot insert same value \n";
            return;
        }
        else if(key<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    struct node * new1 = createnode(key);
    if(key < prev->data){
        prev->left = new1;
    }
    else{
        prev->right = new1;
    }
}

void even(struct node * root){
    if(root != NULL){
        even(root->left);
        if((root->data) % 2 == 0){
            cout<<root->data<<" ";
        }
        even(root->right);
    }
}

void odd(struct node * root){
    if(root != NULL){
        odd(root->left);
        if((root->data) % 2 != 0){
            cout<<root->data<<" ";
        }
        odd(root->right);
    }
}
int getheight(struct node * root){
    if(root == NULL){
        return 0;
    }
    else{
        int left=getheight(root->left);
        int right=getheight(root->right);
        if(left > right){
            return (left +1);
        }
        else{
            return (right + 1);
        }
    }
}
int main(){
    struct node *p=createnode(10);
    struct node *p1=createnode(9);
    struct node *p2=createnode(15);
    struct node *p3=createnode(14);
    struct node *p4=createnode(16);

    p->left=p1;
    p->right=p2;
    p2->left=p3;
    p2->right=p4;

    posttraversal(p);
    cout<<endl;
    pretraversal(p);
    cout<<endl;
    intraversal(p);
    struct node * find=search(p,15);
    if(find!=NULL){
        cout<<"\nfound element "<<find->data<<endl;
    }
    else{
        cout<<"not found \n";
    }
    // deletenode(p,15);
    // intraversal(p);
    // cout<<endl;
    // insertnode(p,15);
    // intraversal(p);
    // cout<<endl;
    // even(p);
    // cout<<endl;
    // odd(p);
    cout<<endl;
    cout<<getheight(p);
}