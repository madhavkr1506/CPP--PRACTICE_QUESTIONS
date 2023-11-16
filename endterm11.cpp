#include<bits/stdc++.h>
#include<fstream>
using namespace std;
void bubblesort(int arr[],int num){
    for(int i=0;i<num-1;i++){
        for(int j=0;j<num-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void printarray(int arr[],int num){
    for(int i=0;i<num;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
        ofstream input;
        input.open("earth1.txt");
        input<<"hello madhav";
        input<<"\nhello rohit how are you\n";
        input.close();
        ifstream output;
        output.open("earth1.txt");
        string line;
        while(getline(output,line)){
            cout<<line<<"\n";
        }
        output.close();
        input.open("earth1.txt",ios :: app);

        int num;
        cin>>num;
        int arr[num];
        for(int i=0;i<num;i++){
            cin>>arr[i];
            // input<<arr[i]<<" ";
        }
        bubblesort(arr,num);
        // input<<"\n";
        for(int i=0;i<num;i++){
            if(arr[i]>10){
                input<<arr[i]<<" ";
            }
        }

        


        // int a;
        // cin>>a;
        // input<<a;
        // int b;
        // cin>>b;
        // input<<b;
        // int res=a+b;
        // input<<res;
        input.close();
        output.open("earth1.txt",ios :: app);
        string line1;
        while(getline(output,line1)){
            cout<<line1<<"\n";
        }
        output.close();
return 0;
}