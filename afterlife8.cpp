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
struct node * createtree(int arr[],int num,int i){
    struct node * newnode =NULL;
    if(i<num){
        newnode=createnode(arr[i]);
        newnode->left=createtree(arr,num,2*i+1);
        newnode->right=createtree(arr,num,2*i+2);
    }
    return newnode;
}
struct node * insert(struct node * root,int value){
    if(root==NULL){
        return createnode(value);
    }
    if(value == root->data){
        return root;
    }
    else if(value < root->data){
        root->left = insert(root->left,value);
    }
    else{
        root->right = insert(root->right,value);
    }
    return root;
}
struct node * inorderprecedence(struct node * root){
    root=root->left;
    while(root->right != NULL){
        root=root->right;
    }
    return root;
}
struct node * deletenode(struct node * root,int value){
    struct node *ipre;
    if(root== NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    if(value < root->data){
        root->left=deletenode(root->left,value);
    }
    else if(value > root->data){
        root->right=deletenode(root->right,value);
    }
    else{
        ipre=inorderprecedence(root);
        root->data=ipre->data;
        root->left=deletenode(root->left,ipre->data);
    }
    return root;
}
struct node * search(struct node * root, int data, int level) {
    if (root == NULL) {
        cout << data << " not found" << endl;
        return NULL;
    }
    if (data == root->data) {
        cout << "Found " << data << " at position " << level << endl;
        return root;
    } else if (data < root->data) {
        return search(root->left, data, level + 1);
    } else {
        return search(root->right, data, level + 1);
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
void preorder(struct node * root){
    if(root != NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
int getheight(struct node * root){
    if(root==NULL){
        return 0;
    }
    else{
        int left=getheight(root->left);
        int right=getheight(root->right);
        if(left > right){
            return (left + 1);
        }
        else{
            return (right + 1);
        }
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
void evenposition_oddposition_element(struct node * root,int &position ,bool iseven){
    if(root != NULL){
        evenposition_oddposition_element(root->left,position,iseven);
        position++;
        if((position % 2 == 0 && iseven) || (position % 2 != 0 && !iseven)){
            cout<<root->data<<" ";
        }
        evenposition_oddposition_element(root->right,position,iseven);
    }
}
int main(){
    int num;
    cin>>num;
    int arr[num];
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }
    struct node * tree=createtree(arr,num,0);
    inorder(tree);
    cout<<endl;
    // int sea;
    // cin>>sea;
    // struct node * find=search(tree,sea,1);
    // if(find != NULL){
    //     cout<<sea<<" found\n";
    // }
    // else{
    //     cout<<"not found\n";
    // }
    // cout<<endl;
    // int del;
    // cin>>del;
    // cout<<endl;
    // deletenode(tree,del);
    // inorder(tree);
    // cout<<endl;
    // int ins;
    // cin>>ins;
    // insert(tree,ins);
    // inorder(tree);
    int evenposition=0;
    evenposition_oddposition_element(tree,evenposition,true);
    cout<<endl;
    int oddpositionelement=0;
    evenposition_oddposition_element(tree,oddpositionelement,false);
    cout<<endl;
    even(tree);
    cout<<endl;
    odd(tree);
    cout<<endl;
    cout<<getheight(tree);
return 0;
}
