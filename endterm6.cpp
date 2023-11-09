#include<iostream>
using namespace std;
void printarray(int arr[],int num){
    for(int i=0;i<num;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    int temp;
    do{
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }while(i<j);
    temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;
    return j;
}
void quicksort(int arr[],int low,int high){
    int position;
    if(low<high){
        position=partition(arr,low,high);
        quicksort(arr,low,position-1);
        quicksort(arr,position+1,high);
    }
}
int main(){
    int num;
    cin>>num;
    int *arr=new int[num];
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }
    quicksort(arr,0,num-1);
    printarray(arr,num);
    int extra;
    cin>>extra;
    int newsize=num+extra;
    int *newarray=new int[newsize];
    for(int i=0;i<num;i++){
        newarray[i]=arr[i];
    }
    for(int i=num;i<newsize;i++){
        cin>>newarray[i];
    }
    quicksort(newarray,0,newsize-1);
    printarray(newarray,newsize);
    delete[] arr;
    delete[] newarray;
return 0;
}



// #include<iostream>
// using namespace std;

// void printarray(int arr[], int num) {
//     for (int i = 0; i < num; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// int partition(int arr[], int low, int high) {
//     int pivot = arr[low];
//     int i = low + 1;
//     int j = high;
//     int temp;
//     do {
//         while (arr[i] <= pivot) {
//             i++;
//         }
//         while (arr[j] > pivot) {
//             j--;
//         }
//         if (i < j) {
//             temp = arr[i];
//             arr[i] = arr[j];
//             arr[j] = temp;
//         }
//     } while (i < j);
//     temp = arr[low];
//     arr[low] = arr[j];
//     arr[j] = temp;
//     return j;
// }

// void quicksort(int arr[], int low, int high) {
//     int position;
//     if (low < high) {
//         position = partition(arr, low, high);
//         quicksort(arr, low, position - 1);
//         quicksort(arr, position + 1, high);
//     }
// }

// int main() {
//     int num;
//     cin >> num;
//     int *arr = new int[num];
//     for (int i = 0; i < num; i++) {
//         cin >> arr[i];
//     }
//     quicksort(arr, 0, num - 1);
//     printarray(arr, num);

//     int extra;
//     cin >> extra;
//     int newsize = num + extra;
//     int *newarray = new int[newsize];
//     for (int i = 0; i < num; i++) {
//         newarray[i] = arr[i];
//     }
//     for (int i = num; i < newsize; i++) {
//         cin >> newarray[i];
//     }
//     quicksort(newarray, 0, newsize - 1);
//     printarray(newarray, newsize);

//     delete[] arr;
//     delete[] newarray;
//     return 0;
// }
