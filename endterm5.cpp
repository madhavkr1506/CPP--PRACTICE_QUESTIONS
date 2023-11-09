#include<iostream>
#include<string.h>

using namespace std;
struct node{
    int size;
    int top;
    char *arr;
};
int isfull(struct node * ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}
int isempty(struct node * ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int stacktop(struct node * ptr){
    return ptr->arr[ptr->top];
}
int operator1(char ch){
    if(ch == '*' || ch == '/' || ch == '+' || ch == '-'){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct node * ptr,int value){
    if(isfull(ptr)){
        cout<<"stack will overflow.\n";
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=value;
    }
}
char pop(struct node * ptr){
    if(isempty(ptr)){
        cout<<"stack underflow\n";
    }
    else{
        int a=ptr->arr[ptr->top];
        ptr->top--;
        return a;
    }
}
int inorderprecedence(char ch){
    if(ch == '*' || ch == '/'){
        return 3;
    }
    else if(ch == '+' || ch == '-'){
        return 2;
    }
    else{
        return 0;
    }
}
char * infixtopostfix(char * infix){
    struct node * ptr=(struct node *)malloc(sizeof(struct node ));
    ptr->size=10;
    ptr->top=-1;
    ptr->arr=(char *)malloc(ptr->size * sizeof(char));
    char * postfix=(char *)malloc((strlen(infix) + 1 ) * sizeof(char));
    int i=0;
    int j=0;
    while(infix[i]!='\0'){
        if(!operator1(infix[i])){
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else{
            if(inorderprecedence(infix[i]) > inorderprecedence(stacktop(ptr))){
                push(ptr,infix[i]);
                i++;
            }
            else{
                postfix[j]=pop(ptr);
                j++;
            }
        }
    }
    while(!isempty(ptr)){
        postfix[j]=pop(ptr);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}


int main(){
    char infix[100];
    cin>>infix;
    cout<<"postfix is : "<<infixtopostfix(infix)<<endl;
return 0;
}