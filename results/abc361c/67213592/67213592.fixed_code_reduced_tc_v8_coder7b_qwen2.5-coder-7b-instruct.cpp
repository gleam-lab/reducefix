#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &val : v){
        cin >> val;
    }
    
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    
    for(int i=0; i<n; ++i){
        max_heap.push(v[i]);
        min_heap.push(v[i]);
    }
    
    for(int i=0; i<k; ++i){
        max_heap.pop();
        min_heap.pop();
    }
    
    cout << max_heap.top() - min_heap.top() << '\n';
    return 0;
}