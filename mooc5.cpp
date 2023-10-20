#include<iostream>
#include<cstring>
using namespace std;
struct stack{
    int size;
    int top;
    char * arr;
};
int stacktop (struct stack * ptr){
    return ptr->arr[ptr->top];
}
int isfull(struct stack * ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}
int isempty(struct stack * ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct stack * ptr,int val){
    if(!isfull(ptr)){
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}
int pop(struct stack * ptr){
    if(!isempty(ptr)){
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int isoperator(char ch){
    if(ch == '*' || ch == '/' || ch == '+' || ch == '-'){
        return 1;
    }
    else{
        return 0;
    }
}
int precedence(char ch){
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
    struct stack * ptr=(struct stack * )malloc(sizeof(struct stack));
    ptr->size=10;
    ptr->top=-1;
    ptr->arr=(char *)malloc(ptr->size * sizeof(char));
    char * postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i=0;
    int j=0;
    while(infix[i]!='\0'){
        if(!isoperator(infix[i])){
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else{
            if(precedence(infix[i])>precedence(stacktop(ptr))){
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
    cout<<infixtopostfix(infix);
return 0;
}