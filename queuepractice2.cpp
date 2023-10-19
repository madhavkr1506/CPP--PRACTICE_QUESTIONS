#include<iostream>
#include<cstring>
using namespace std;

struct queue{
    int size;
    int f;
    int r;
    char ** arr;
};

int isempty(struct queue * ptr){
    if(ptr->r == ptr->f){
        return 1;
    }
    else{
        return 0;
    }
}

int isfull(struct queue * ptr){
    if(ptr->r == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct queue * ptr,char * data){
    if(isfull(ptr)){
        cout<<"overflow\n";
    }
    else{
        ptr->r++;
        ptr->arr[ptr->r] = (char *)malloc(strlen(data) + 1);
        strcpy(ptr->arr[ptr->r],data);
        cout<<"enqueue "<<data<<endl;
    }
}

char * dequeue(struct queue * ptr){
    char * a = NULL;
    if(isempty(ptr)){
        cout<<"undreflow\n";
    }
    else{
        ptr->f++;
        a=ptr->arr[ptr->f];
        cout<<"dequeue "<<a<<endl;
    }
    return a;
}

char * queuetop(struct queue * ptr){
    return ptr->arr[0];
}

char * queuebottom(struct queue * ptr){
    return ptr->arr[ptr->r];
}

char * peek(struct queue * ptr , int i){
    if((ptr->r - i + 1) < 0){
        cout<<"invalid position\n";
        return NULL;
    }
    else{
        return ptr->arr[ptr->r - i + 1];
    }
}

void bubblesort(struct queue * ptr){
    if(ptr == NULL){
        return;
    }
    int n=ptr->r + 1;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(strcmp(ptr->arr[j],ptr->arr[j+1])>0){
                swap(ptr->arr[j],ptr->arr[j+1]);
            }
        }
    }
}
int main(){
    struct queue * q = (struct queue * )malloc(sizeof(struct queue));
    q->size=10;
    q->r=-1;
    q->f=-1;
    q->arr=(char ** )malloc(q->size * sizeof(char *));
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        char data[100];
        cin>>data;
        enqueue(q,data);
    }
    for(int j=1;j<=q->r + 1;j++){
        cout<<peek(q,j)<<" ";
    }
    cout<<endl;
    // dequeue(q);
    bubblesort(q);
    for(int j=1;j<=q->r-q->f;j++){
        cout<<peek(q,j)<<" ";
    }

return 0;
}