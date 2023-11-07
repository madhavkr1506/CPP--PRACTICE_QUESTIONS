#include<iostream>
using namespace std;
void heapify(int arr[],int n,int i){
    int large=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[l] > arr[large]){
        large=l;
    }
    if(r<n && arr[r] > arr[large]){
        large=r;
    }
    if(large != i){
        swap(arr[i],arr[large]);
        heapify(arr,n,large);
    }
}
void mheapify(int arr[],int n,int i){
    int large=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[l] < arr[large]){
        large=l;
    }
    if(r<n && arr[r] < arr[large]){
        large=r;
    }
    if(large != i){
        swap(arr[i],arr[large]);
        mheapify(arr,n,large);
    }
}
void buildmaxheap(int arr[],int n){
    for(int i=(n-2)/2;i>=0;i--){
        heapify(arr,n,i);
    }
}
void heapsort(int arr[],int n){
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
void buildminheap(int arr[],int n){
    for(int i=(n-2)/2;i>=0;i--){
        mheapify(arr,n,i);
    }
}
void mheapsort(int arr[],int n){
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        mheapify(arr,i,0);
    }
}
void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void deletenode(int arr[],int &n){
    arr[0]=arr[n-1];
    n=n-1;
    heapify(arr,n,0);
}
void deletevalue(int arr[],int &n,int value){
    for(int i=0;i<n;i++){
        if(arr[i]==value){
            arr[i]=arr[n-1];
            n=n-1;
            heapify(arr,n,i);
            i--;
        }
    }
}
// void deleteValuesAfter(int arr[], int &n, int value) {
//     // Iterate through the array in reverse order
//     for (int i = n - 1; i >= 0; i--) {
//         if (arr[i] >= value) {
//             arr[i] = arr[n - 1]; // Replace the value with the last element
//             n = n - 1; // Reduce the size of the array
//             heapify(arr, n, i); // Heapify to maintain the heap property
//         }
//     }
// }
void deleteValuesAfter(int arr[], int &n, int value) {
    int originalSize = n; // Store the original size of the array
    n = 0; // Reset the size of the array

    // Iterate through the original array
    for (int i = 0; i < originalSize; i++) {
        if (arr[i] < value) {
            arr[n] = arr[i]; // Keep elements less than the specified value
            n++; // Increment the size of the array
        }
    }
}

void insertnode(int arr[],int n,int i){
    int p=(i-1)/2;
    if(p>=0){
        if(arr[i]>arr[p]){
            swap(arr[i],arr[p]);
            insertnode(arr,n,p);
        }
    }
}
void insertdata(int arr[],int &n,char i){
    n=n+1;
    arr[n-1]=i;
    insertnode(arr,n,n-1);
}
int main(){
    // int n;
    // cin>>n;
    // int arr[n];
    // // int num=0;
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    //     // int val;
    //     // cin>>val;
    //     // insertdata(arr,num,val);
    // }
    // buildmaxheap(arr,n);
    // // heapsort(arr,n);
    // // deletenode(arr,n);
    // // // int del;
    // // // cin>>del;
    // // // deletevalue(arr,n,del);
    // int start;
    // cin>>start;
    // // int lst;
    // // cin>> lst;
    // // for(int i=start;i<=lst;i++){
    // deletevalue(arr,n,start);
    // // }
    // printarray(arr,n);
    // // cout<<endl;
    // // // cout<<arr[0]+arr[n-1];
    // // // cout<<arr[0];
    // // int choice ;
    // // while(true){
    // //     cin>>choice;
    // //     switch(choice){
    // //         case 2 : buildmaxheap(arr,n);
    // //         heapsort(arr,n);
    // //         printarray(arr,n);
    // //     }
    // // }
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    buildmaxheap(arr, n);

    // int valueToDeleteAfter;
    // cin >> valueToDeleteAfter;

    // // Call the deleteValuesAfter function to delete values greater than or equal to the specified value
    // deleteValuesAfter(arr, n, valueToDeleteAfter);

    int val;
    while(true){
        cin>>val;
        switch(val){
            case 1 : 
            buildmaxheap(arr,n);
            heapsort(arr,n);
            printarray(arr,n);
            break;
            case 2 : buildminheap(arr,n);
            mheapsort(arr,n);
            printarray(arr,n);
            break;
            default:
            cout<<"invalid choice ";
            exit(0);
            break;
        }
    }
    return 0;
}