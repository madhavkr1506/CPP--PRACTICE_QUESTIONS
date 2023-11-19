#include<iostream>
#include<queue>
using namespace std;

int main(){
    int num;
    cin >> num;

    // Using std::greater for min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for(int i = 0; i < num; i++){
        int element, priority;
        cin >> element >> priority;
        pq.push({priority, element});
    }

    while (!pq.empty()){
        cout << pq.top().second << " priority " << pq.top().first << endl;
        pq.pop();
    }

    return 0;
}
