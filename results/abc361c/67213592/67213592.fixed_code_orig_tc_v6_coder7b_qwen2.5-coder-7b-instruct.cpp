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
    for(auto& val : v) {
        cin >> val;
    }
    
    priority_queue<int, vector<int>, greater<int>> min_heap(v.begin(), v.end()); // Min heap to store smallest elements
    priority_queue<int> max_heap(v.begin(), v.end()); // Max heap to store largest elements
    
    // Remove k elements from the min heap
    for(int i = 0; i < k; ++i) {
        min_heap.pop();
    }
    
    // Remove k elements from the max heap
    for(int i = 0; i < k; ++i) {
        max_heap.pop();
    }
    
    // The difference between the maximum element in the remaining max heap and the minimum element in the remaining min heap is the result
    cout << max_heap.top() - min_heap.top() << endl;
}